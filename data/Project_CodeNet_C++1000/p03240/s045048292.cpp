#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>x(n),y(n),h(n);
    for(ll i=0;i<n;i++){
        cin >> x[i] >> y[i] >> h[i];
    }
    ll cx,cy,H;
    for(ll ix=0;ix<=100;ix++){
        bool judge=true;
        for(ll iy=0;iy<=100;iy++){
            judge=true;
            for(ll i=0;i<n;i++){
                if(h[i]!=0){
                    H=h[i]+abs(x[i]-ix)+abs(y[i]-iy);
                    break;
                }
            }
            for(ll i=0;i<n;i++){
                if(h[i]==0){
                    if(H-abs(x[i]-ix)-abs(y[i]-iy)>0){
                        judge=false;
                        break;
                    }
                }
                else{
                    if(H!=h[i]+abs(x[i]-ix)+abs(y[i]-iy)){
                        judge=false;
                        break;
                    }
                }
            }
            if(judge){
                cx=ix,cy=iy;
                break;
            }
        }
        if(judge){
            break;
        }
    }
    cout << cx << " " << cy << " " << H << endl;
}