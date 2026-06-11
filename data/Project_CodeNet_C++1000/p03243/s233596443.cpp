#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi v;
    for (int i = 111; i <= 999; i += 111) {
      v.push_back(i);
    }
    rep(i, 0, v.size()) {
      if (v[i] >= n) {
        cout << v[i];
        break;
      }
    }
    return 0;
}