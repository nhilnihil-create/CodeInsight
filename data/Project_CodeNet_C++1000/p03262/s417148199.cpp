#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
ll gcd(ll x,ll y){
    if (y == 0) return x;
    return gcd(y, x%y);
}
int main(void){
    int n,a;cin>>n>>a;
    vector<int> x(n+1);
    rep(i,n) cin>>x[i];
    x[n]=a;
    sort(x.begin(),x.end());
    int g=x[1]-x[0];
    rep(i,n)g=gcd(g,(x[i+1]-x[i]));
    cout<<g<<endl;
}