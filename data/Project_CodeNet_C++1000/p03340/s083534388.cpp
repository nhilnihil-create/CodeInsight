#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
typedef long long ll;
const int mod = 1e9 + 7;
int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    int right = 0;
    int sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n  &&  (sum ^ a[right]) == (sum + a[right])){
            sum += a[right];
            ++right;
        }
        ans += right - left;
        if (left == right) ++right;
        else sum -= a[left]; 
    }

    cout << ans << endl;

    return 0;
}