#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define stl_repr(itr, x) for (auto itr = x.rbegin(); itr != x.rend(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

using llong = long long int;

const static int MOD = 1000000007;
const static int IINF = INT_MAX;
const static llong LINF = LLONG_MAX;
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};

template<typename T> T my_gcd(T a, T b) {
    return (a ? my_gcd(b % a, a) : b);
}
template<typename T> T my_lcm(T a, T b){
    return a * b / my_gcd(a, b);    
}

vector<int> check;

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<llong> A(n);
    rep(i, n) cin >> A[i];

    llong ans = 0;
    int right = 0;
    llong sum = 0, tmp = 0;
    rep(left, n) {
    	while (right < n && (sum + A[right]) == (tmp ^ A[right])) {
    		tmp ^= A[right];
    		sum += A[right];
    		++right;
    	}
    	ans += right - left;

    	if (left == right) ++right;
    	else {
    		sum -= A[left];
    		tmp ^= A[left];

    	}
    }

    cout << ans << endl;

    return 0;
}