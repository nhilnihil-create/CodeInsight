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

const int MAX = 100;

int main() {
    speed();
    int N, A[MAX], D, X;
    cin >> N;
    cin >> D >> X;
    rep(i, 0, N) cin >> A[i];
    int ans = X;
    rep(i, 0, N) {
        int temp = ((D-1) / A[i]) + 1;
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}