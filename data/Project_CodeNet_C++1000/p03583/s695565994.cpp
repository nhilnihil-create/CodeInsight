#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<ll, ll>;
using P3 = pair<P,int>;
using PP = pair<P, P>;
constexpr ll INF = 1LL << 60;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr int di8[] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int dj8[] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr double EPS = 1e-9;


int main(){
    ll n;
    cin >> n;
    constexpr ll MAX_X = 3500;
    for(ll x=1;x<=MAX_X;x++){
        for(ll y=1;y<=MAX_X;y++){
            ll a = 4*x*y - n*(x+y);
            if(a <= 0) continue;
            ll z = (n*x*y)/a;
            if(z >= 0 && z <= MAX_X && n*(x*y+y*z+z*x) == 4*x*y*z){
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    return 0;
}
