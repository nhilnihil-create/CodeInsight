#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pa;
const ll MOD = 1e9 + 7;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}
//-----------------------------------------------------------//

int main() {
    init();
    int n,h,w;
    cin >>n>>h>>w;
    cout << (n-h+1)*(n-w+1)<<endl;
    return 0;
}
