#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll k;cin>>k;
    vector<ll> a(k);
    rep(i,k)cin>>a[i];
    if(a[k-1]!=2){
        cout<<-1<<endl;
        return 0;
    }
    reverse(a.begin(),a.end());
    
    ll tmp=2,tmp2=2;
    rep(i,k){
        if(i==0)continue;
        ll x=(tmp+a[i-1]-1)/a[i],y=(tmp2+a[i]-1)/a[i];
        tmp=x*a[i],tmp2=y*a[i];
        if(x<y){
            cout<<-1<<endl;
            return 0;
        }
    }
    tmp+=(a[k-1]-1);
    cout<<tmp2<<" "<<tmp<<endl;
}
