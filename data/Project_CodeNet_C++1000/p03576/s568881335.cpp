#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,K;
ll x[55];
ll y[55];

int main(){
    cin >> n >> K;
    vector<ll> dx;
    vector<ll> dy;
    for(ll i=0;i<n;i++){
        cin >> x[i] >> y[i];
        dx.push_back(x[i]);
        dy.push_back(y[i]);
    }
    sort(dx.begin(),dx.end());
    sort(dy.begin(),dy.end());
    ll res=abs(dx[n-1]-dx[0])*abs(dy[n-1]-dy[0]);
    for(ll i=0;i<n;i++){
        for(ll k=i+1;k<n;k++){
            for(ll j=0;j<n;j++){
                for(ll l=j+1;l<n;l++){
                    ll lx=dx[i],rx=dx[k],ly=dy[j],ry=dy[l];
                    ll count=0;
                    for(ll c=0;c<n;c++){
                        if(lx<=x[c]&&x[c]<=rx&&ly<=y[c]&&y[c]<=ry) count++;
                    }
                    if(K<=count) res=min(res,abs(rx-lx)*abs(ry-ly));
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}  
