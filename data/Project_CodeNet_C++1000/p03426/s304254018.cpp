#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,w,d;
ll a[303][303];
ll q,l,r;
ll x[90009],y[90009];
ll res[90009];

int main(){
    cin >> h >> w >> d;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >> a[i][j];
            x[a[i][j]]=i;
            y[a[i][j]]=j;
        }
    }
    for(ll i=0;i<=d;i++) res[i]=0;
    for(ll i=d+1;i<=h*w;i++){
        res[i]=res[i-d]+abs(x[i]-x[i-d])+abs(y[i]-y[i-d]);
    }
    cin >> q;
    for(ll i=0;i<q;i++){
        cin >> l >> r;
        cout << res[r]-res[l] << endl;
    }
}
