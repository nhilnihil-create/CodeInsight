#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000000;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

// a = max(a, b), a = min(a, b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main(){
    ll N;
    cin >> N;
    ll w;
    REP(h, 3501)REP(n, 3501){
        if(h == 0 || n == 0) continue;
        ll bunbo = N * h * n, bunshi = 4 * h * n - N * (h + n);
        if (bunshi == 0) continue;
        if (bunbo % bunshi == 0) {
            ll w = bunbo / bunshi;
            if (w >= 0) {
                cout << h << " " << n << " " << bunbo / bunshi;
                return 0;
            }
        }
    }
}
