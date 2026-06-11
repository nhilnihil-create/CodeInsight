#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,k;cin>>n>>k;
    vector<ll> X(n),Y(n),x(n),y(n);
    rep(i,n){
        cin>>x[i]>>y[i];
        X[i]=x[i];Y[i]=y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll res=5*(1e+18);
    for(int lx=0;lx<n;lx++){
        for(int ly=0;ly<n;ly++){
            for(int rx=lx+1;rx<n;rx++){
                for(int ry=ly+1;ry<n;ry++){
                    //cout<<x[lx]<<" "<<x[rx]<<" "<<y[ly]<<" "<<y[ry]<<endl;
                    int tmp=0;
                    rep(i,n) if(x[lx]<=X[i]&&X[i]<=x[rx]&&y[ly]<=Y[i]&&Y[i]<=y[ry])tmp++;
                    if(tmp>=k)chmin(res,(x[rx]-x[lx])*(y[ry]-y[ly]));
                }
            }
        }
    }
    cout<<res<<endl;
}
