#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

//重みある時
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

int main() {
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; ++h) {
        for (ll n = 1; n <=3500 ; ++n) {
            ll bunsi = N*h*n,bunbo = 4*h*n-N*n-N*h;
            if(bunbo > 0 && bunsi%bunbo == 0){
                cout << h << ' ' << n << ' ' << (bunsi/bunbo) << endl;
                return 0;
            }
        }
    }
    return 0;
}
