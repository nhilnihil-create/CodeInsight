#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

ll solve(ll x) {
    if(x % 2 == 0) {
        if((x + x % 2) / 2 % 2 == 1) {
            x = x ^ 1;
        }
    }else {
        if(((x + x % 2) / 2) % 2 == 1) {
            x = 1;
        }else {
            x = 0;
        }
    }
    return x;
}

int main() {
    ll A, B; cin >> A >> B;
    cout << (solve(A - 1) ^ solve(B)) << endl;
}
