#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    ll ta=0,tb=0;
    rep(i,n){
        if(a[i]>b[i])ta+=(a[i]-b[i]);
        else tb+=(b[i]-a[i])/2;
    }
    //cout<<ta<<" "<<tb<<endl;
    if(ta<=tb)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
