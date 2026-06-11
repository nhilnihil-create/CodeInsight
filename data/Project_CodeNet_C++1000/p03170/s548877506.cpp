#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>

// 1 if win. 0 if loss
bool state[100002];
bool calculated[100002];
int n, k;
vi ar;

void recurse(int pos) {
    calculated[pos] = 1;
    bool loserAccessible = false;
    for (int i : ar) {
        if (i + pos <= k) {
            if (!calculated[i + pos]) recurse(i + pos);
            if (!state[i + pos]) loserAccessible = 1;
        } else
            break;
    }
    state[pos] = loserAccessible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    ar.resize(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(all(ar));

    for (int i = k; i > k - ar[0]; i--) state[i] = 0, calculated[i] = 1;
    recurse(0);
    cout << (state[0] ? "First" : "Second");
}