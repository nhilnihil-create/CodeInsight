#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>x(n),y(n),h(n);
    ll k=-1;
    for (int i = 0; i < n; ++i) {
        cin >>x[i]>>y[i]>>h[i];
        if(h[i]>0)k=i;
    }
    ll ax,ay,ah;
    for (int cx = 0; cx <=100 ; ++cx) {
        for (int cy = 0; cy <=100; ++cy) {
            ll H;bool flg=true;
            H=h[k]+abs(x[k]-cx)+abs(y[k]-cy);
            for (int i = 0; i < n; ++i) {
                ll tmp=max(H-abs(x[i]-cx)-abs(y[i]-cy),0LL);
                if(tmp!=h[i]){
                    flg=false;
                    break;
                }
            }
            if(flg){
                ax=cx;ay=cy;ah=H;
            }
        }
    }
    cout <<ax<<" "<<ay<< " "<<ah <<endl;
    return 0;
}