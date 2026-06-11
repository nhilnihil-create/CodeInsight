#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    ll n;
    cin >> n;
    ll pmax = 4 * n;
    for(ll p = 1; p < pmax; p++){
        if (4*p - n <= 0) continue;
        for(ll q = p; q <= 3500; q++){
            if (4*p*q - n*p - n*q <= 0) continue;
            for(ll r = q; r <= 3500; r++){
                if (4*p*q*r == n * (p*q + q*r + r*p)){
                    cout << p << " " << q << " " << r << endl;
                    return 0;
                }
            }
        }
    }
}