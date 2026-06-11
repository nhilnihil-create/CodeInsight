#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
string s;
cin >> n >> s;
vector<int> e(n+1,0),w(n+1,0);
rep(i,n){
    if(s[i]=='E'){
        e[i + 1] = e[i] + 1;
        w[i + 1] = w[i];
    }
    else{
        e[i + 1] = e[i];
        w[i + 1] = w[i]+1;
    }
}
int ans=1e9;
rep(i,n){
    int w_num = w[i];
    int e_num = e[n] - e[i + 1];
    chmin(ans, w_num +e_num);
}
cout << ans << endl;
}