#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    vector<int> x(n),y(n);
    vector<int> xary,yary;
    
    rep(i,n){
        cin >> x[i] >> y[i];
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(xary.begin(),xary.end());
    sort(yary.begin(),yary.end());

    ll ans = 1LL * (xary[n-1]-xary[0]) * (yary[n-1]-yary[0]);

    rep(xi,n){
        for (int xj=xi+1;xj<n;xj++){
            rep(yi,n){
                for (int yj=yi+1;yj<n;yj++){
                    int num = 0;
                    ll ix = xary[xi], jx = xary[xj];
                    ll iy = yary[yi], jy = yary[yj];

                    rep(i,n){
                        if (ix<=x[i]&&x[i]<=jx&&iy<=y[i]&&y[i]<=jy){
                            num++;
                        }
                    }
                    if (num >= k) ans = min (ans , 1LL * (jx -ix) * (jy - iy) );
                }
            }
        }
    }

    cout << ans ;




    // vector<pair<ll,ll>> q(n);
    // rep(i,n){
    //     ll a,b;
    //     cin >> a >> b;
    //     pair <ll,ll>  w(a,b);
    //     q[i]=w;
    // }
    // sort(q.begin(),q.end());
    // ll ans = 3999999996000000001;
    // for (int i=0;i<n-k+1;i++){
    //     ll xmin = q[i].first;
        
    //         ll ymin = 1000000000;
    //         ll ymax = -1000000000;
    //     for (int l=i+k-1;l<n;l++){
    //         ll xmax = q[l].first;
    //         for (int j=i;j<l+1;j++){
    //             ymin = min(ymin,q[j].second);
    //             ymax = max(ymax,q[j].second);
                
    //         }
    //         ans = min (ans,(xmax-xmin)*(ymax-ymin));
    //     }     
    // }
    // cout << ans;

    return 0;
}