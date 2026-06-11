#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,tmp=INF,sum=0; cin>>n;
    rep(i,n){
        int a,b; cin>>a>>b;
        if(a>b)chmin(tmp,b);
        sum+=a;
    }
    if(tmp==INF)cout<<0<<endl;
    else cout<<sum-tmp<<endl;
}