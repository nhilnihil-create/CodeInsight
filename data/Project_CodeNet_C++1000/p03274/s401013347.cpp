#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9 + 7;
set<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main() {
    int N, K;
    cin >> N >> K;
    vll x(N + 1);
    repp(i, N) cin >> x[i];
    vll ans;
    repp(i, N - K + 1) {
        int a = x[i];
        int b = x[i + K - 1];
        ans.push_back(abs(a) + abs(a - b));
        ans.push_back(abs(b) + abs(a - b));
    }
    sort(ans);
    cout << ans[0] << endl;
}
