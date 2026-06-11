#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define endl '\n'

const int N = 1e5;

struct Cake{
    ll x, y, z;
};

pll v[N+5];
Cake arr[N+5];

ll value(Cake a, bool p1, bool p2, bool p3){
    ll ret = 0;

    if(p1 == 1) ret += a.x;
    else ret += (a.x < 0? abs(a.x) : -a.x);

    if(p2 == 1) ret += a.y;
    else ret += (a.y < 0? abs(a.y) : -a.y);

    if(p3 == 1) ret += a.z;
    else ret += (a.z < 0? abs(a.z) : -a.z);

    return ret;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m; cin >>n >>m;
    for(int i = 0; i<n; i++) cin >>arr[i].x >>arr[i].y >>arr[i].z;

    ll ans = 0;
    ll t1, t2, t3;
    for(int i = 0; i<=1; i++){
        for(int j = 0; j<=1; j++){
            for(int k = 0; k<=1; k++){

                ll aux = 0;
                t1 = t2 = t3 = 0;

                for(int a = 0; a<n; a++){
                    //if(!p1 && !p2 && !p3) cout <<value(arr[a]) <<endl;
                    v[a] = {-value(arr[a], i, j, k), a};
                }

                sort(v, v+n);

                for(int a = 0; a<m; a++){
                    t1 += arr[v[a].se].x;
                    t2 += arr[v[a].se].y;
                    t3 += arr[v[a].se].z;
                }

                aux = abs(t1) + abs(t2) + abs(t3);

                if(aux > ans) ans = aux;

            }
        }
    }


    cout <<ans <<endl;
    return 0;
}
