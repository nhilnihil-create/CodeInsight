#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    int64_t A, B;
    int K; cin >> A >> B >> K;
    set<int> s;
    rep(i, 0, K) {
        if (A + i <= B) s.insert(A + i);
        if (B - i >= A) s.insert(B - i);
    }
    trav(n, s) cout << n << endl;
    return 0;
}