#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,w,d;
    int z;
    cin >> h >> w >> d;
    vector <int> xx(h*w+1,0),yy(h*w+1,0);
    rep(i,h){
        rep(j,w){
            cin >> z;
            xx[z]=i+1;
            yy[z]=j+1;
        }
    }

    ll q;
    cin >> q;
    int l,r;
    vector <ll> ans(q,0);

    vector <ll> gg(h*w+1);

    rep(i,h*w+1){
        if(i<d){
            gg[i]=0;
        }
        else{
            gg[i]=gg[i-d]+abs(xx[i]-xx[i-d])+abs(yy[i]-yy[i-d]);
        }
        //cout << gg[i] << endl;
    }
    
    rep(i,q){
        //cout << i << endl;
        cin >> l >> r;
        ans[i]=gg[r]-gg[l];
        
    }

    rep(i,q){
        cout << ans[i] << endl;
    }
    

    return 0;
}