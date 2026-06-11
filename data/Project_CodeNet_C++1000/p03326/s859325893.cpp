#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n,m;cin >> n >> m;
    vector<ll> x(n),y(n),z(n);
    for(int i=0;i<n;i++) cin >> x[i] >> y[i] >> z[i];
    ll mx=-LINF;
    for(int bit=0;bit<(1<<3);bit++){
        vector<ll> xx=x;
        vector<ll> yy=y;
        vector<ll> zz=z;
        for(int i=0;i<3;i++){
            if((bit>>0)&1){
                for(int i=0;i<n;i++){
                    xx[i]=-x[i];
                }
            }
            if((bit>>1)&1){
                for(int i=0;i<n;i++){
                    yy[i]=-y[i];
                }
            }
            if((bit>>2)&1){
                for(int i=0;i<n;i++){
                    zz[i]=-z[i];
                }
            }
        }
        vector<ll> xyz(n);
        for(int i=0;i<n;i++) xyz[i]=xx[i]+yy[i]+zz[i];
        sort(xyz.rbegin(),xyz.rend());
        ll sum=0;
        for(int i=0;i<m;i++){
            sum+=xyz[i];
        }
        mx=max(mx,sum);
        //cout << sum << endl;
    }
    cout << mx << endl;
    return 0;
}