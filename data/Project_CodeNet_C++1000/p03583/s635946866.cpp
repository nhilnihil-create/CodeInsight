#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;

int main(){
    ll n, m = 3501;
    cin >> n;
    for(int i = 1; i < m ; i++){
        for(int j = 1; j < m; j++){
            ll x = 4 * i * j - n * i - n * j;
            if(x <= 0) continue;
            ll y = n * i * j;
            if(y % x == 0 && y / x < m) {
                cout << i << " " << j << " " << y / x << endl;
                return 0;
            }
        }
    }
}
