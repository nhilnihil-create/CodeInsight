#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>> a(h,vector<ll>(w));
    vector<ll> y0, x0, y1, x1;
    rep(i,h)rep(j,w) cin>>a[i][j];
    rep(i,h){
        rep(j,w){
            if(a[i][j]%2!=0){
                if(j!=w-1){
                    y0.push_back(i+1);
                    x0.push_back(j+1);
                    y1.push_back(i+1);
                    x1.push_back(j+2);
                    a[i][j]--;
                    a[i][j+1]++;
                }else if(i!=h-1){
                    y0.push_back(i+1);
                    x0.push_back(j+1);
                    y1.push_back(i+2);
                    x1.push_back(j+1);
                    a[i][j]--;
                    a[i+1][j]++;                }
            }
        }
    }
    cout<<y0.size()<<endl;
    rep(i,y0.size()) cout<<y0[i]<<' '<<x0[i]<<' '<<y1[i]<<' '<<x1[i]<<endl;
    return 0;
}