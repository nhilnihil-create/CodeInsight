#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
#define mt make_tuple
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;
using tlll=tuple<ll,ll,ll>;
int main(){
    int n;
    cin >> n;
    vector<tlll> height,ground;
    ll ansx,ansy,ansh;
    rp(i,n){
        ll x,y,h;
        cin >> x >> y >> h;
        if(h!=0) height.push_back(mt(x,y,h));
        else ground.push_back(mt(x,y,h));
    }
    bool allok=false;
    rp(cx,101){
        rp(cy,101){
            ll nx=get<0>(height[0]);
            ll ny=get<1>(height[0]);
            ll nh=get<2>(height[0]);
            ll nowh=nh+abs(nx-cx)+abs(ny-cy);
            bool ok=true;
            for(int i=1;i<height.size();i++){
                nx=get<0>(height[i]);
                ny=get<1>(height[i]);
                nh=get<2>(height[i]);
                if(nh+abs(nx-cx)+abs(ny-cy)!=nowh){
                    ok=false;
                    break;
                }
            }
            if(!ok) continue;
            rp(i,ground.size()){
                nx=get<0>(ground[i]);
                ny=get<1>(ground[i]);
                nh=get<2>(ground[i]);
                if(nowh-abs(nx-cx)-abs(ny-cy)>0ll){
                    ok=false;
                    break;
                }
            }
            if(ok){
                ansx=cx; ansy=cy; ansh=nowh;
                allok=true;
                break;
            }
        }
        if(allok) break;
    }
    cout << ansx << " " << ansy << " " << ansh << endl;
    return 0;
}