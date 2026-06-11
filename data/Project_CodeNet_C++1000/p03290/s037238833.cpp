#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int d;cin>>d;
    ll g;cin>>g;
    vector<int> p(d),c(d);
    rep(i,d){
        cin>>p[i]>>c[i];
    }
    ll res=1e18;
    for(int tmp=0;tmp<(1<<d);tmp++){
        ll sum=0,tot=0;
        rep(i,d){
            if(tmp&(1<<i)){
                tot+=((i+1)*100)*p[i]+c[i];
                sum+=p[i];
            }
        }
        if(tot>=g){
            chmin(res,sum);
            continue;
        }
        bool ok=false;
        for(int i=d-1;i>=0;i--){
            if(tmp&(1<<i))continue;
            int x=100*(i+1);
            if((g-tot+x-1)/x<p[i]){
                sum+=(g-tot+x-1)/x;
                chmin(res,sum);
                ok=true;
                break;
            }else{
                sum+=p[i]-1;
                tot+=(p[i]-1)*x;
            }
        }
        if(ok)chmin(res,sum);
    }
    cout<<res<<endl;
}