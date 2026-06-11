#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e8;
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int>w(n),e(n);
    rep(i,n-1){
        if(s[i]=='W'){
            w[i]++;
        }
        if(i==n-1)continue;
        w[i+1]=w[i];
    }
    for(int i = n-1;i>=0;i--){
        if(s[i]=='E'){
            e[i]++;
        }
        if(i==0)continue;
        e[i-1]=e[i];
    }
    int M = INF;
    w[-1]=0;
    e[n]=0;
    rep(i,n){
        int now = w[i-1]+e[i+1];
        M = min(M,now);
    }
    cout<<M<<endl;
    return 0;
}
