#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>
#define mod 1000000007
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define srep(i,s,t) for (ll i = s; i < t; i++)
#define drep(i,n) for(ll i = (n)-1; i >= 1; i--)
using namespace std;
typedef long long ll;
typedef vector<vector<char>> field_t;
typedef unsigned long long ull;
typedef pair<ll, ll> point_t;


int main()
{
    ll n;
    cin >> n;
    ll s;
    ll ans=0;
    vector<ll> x(n,0),h(n,0),y(n,0);
    rep(i,n){
        cin >> x[i] >> y[i] >>h[i];
        if(h[i]!=0){
            s=i;
        }
    }
    ll ansx,ansy,ansh;
    rep(dx,101){
        rep(dy,101){
            ansh=h[s]+abs(dx-x[s])+abs(dy-y[s]);
            bool T=true;
            rep(i,n){
                if(h[i]!=max((ll)0,ansh-(abs(dx-x[i])+abs(dy-y[i])))){
                    T=false;
                }
            }
            if(T){
                ansx=dx;
                ansy=dy;
                cout <<ansx <<" "<<ansy<<" "<<ansh<<endl;
                return 0;
            }
        }
    }
    return 0;
}