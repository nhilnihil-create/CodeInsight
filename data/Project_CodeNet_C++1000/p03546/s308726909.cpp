#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,w,a;
ll c[10][10];

int main(){
    cin >> h >> w;
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            cin >> c[i][j];
        }
    }
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            for(ll k=0;k<10;k++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            for(ll k=0;k<10;k++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            for(ll k=0;k<10;k++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            for(ll k=0;k<10;k++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    ll res=0;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >> a;
            if(a>=0) res+=c[a][1];
        }
    }
    cout << res << endl;
}  
