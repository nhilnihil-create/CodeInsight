#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll>x(n),y(n),h(n);
    rep(i,0,n){
        cin>>x.at(i)>>y.at(i)>>h.at(i);
    }
    ll tcx,tcy,th;
        rep(cx,0,101){
            rep(cy,0,101){
                bool c=true;
                vector<ll> H;
                ll hre=INF;
                rep(i,0,n){
                    if(h.at(i)==0) continue;
                    else{
                        ll tmph=h.at(i)+abs(x.at(i)-cx)+abs(y.at(i)-cy);
                        H.push_back(tmph);
                    }
                }
                rep(i,0,H.size()-1){
                    if(H.at(i)!=H.at(i+1))c=false;
                }
                if(c){
                    tcx=cx,tcy=cy,th=H.at(0);
                }
                bool d=true;
                rep(i,0,n){
                    if(h.at(i)!=max((ll)0,th-abs(x.at(i)-tcx)-abs(y.at(i)-tcy)))d=false;
                }
                if(d){
                    cout<<tcx<<' '<<tcy<<' '<<th<<endl;
                    return 0;
                }
            }
        }
return 0;
}