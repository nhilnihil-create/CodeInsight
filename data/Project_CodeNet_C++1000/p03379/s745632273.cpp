//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())

priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


void solve(){
    int n;
    cin >> n;
    vector<llint>x(n);
    vector<llint>t(n);
    for(int i=0;i<n;i++){
        cin >> x[i];
        t[i]=x[i];
    }
    sort(x);
    llint res1=x[n/2-1];
    llint res2=x[n/2];
    for(int i=0;i<n;i++){
        if(t[i]>=res2){
            cout << res1 << endl;
        }
        else{
            cout << res2 << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}


