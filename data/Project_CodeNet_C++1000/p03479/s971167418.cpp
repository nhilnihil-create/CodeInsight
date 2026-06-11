#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> P;
#define FOR(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const ll INF = numeric_limits<ll>::max();
int main()
{
    ll x, y; cin >> x >> y;
    ll c = 1;
    while(1){
        x *= 2;
        if (x <= y) {
            ++c;
        }else{
            break;
        }
    }
    cout << c << endl;
    return 0;
}