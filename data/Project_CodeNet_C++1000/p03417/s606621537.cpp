#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vvvd = vector<vector<vector<double>>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pint = pair<int, int>;
using Graph = vvi;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int main() {
    ll n, m;
    cin >> n >> m;

    if(n >= 2) n -= 2;
    if(m >= 2) m -= 2;

    ll ans = n * m;

    cout << ans << endl;

    return 0;
}
