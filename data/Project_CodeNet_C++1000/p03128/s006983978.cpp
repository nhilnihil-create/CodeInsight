#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 10005;

int n, m;
string dp[N];
int last[N];

int num[10] = {0,2,5,5,4,5,6,3,7,6};
int val[10];

bool comp(string a, string b) {
    if (sz(a) > sz(b)) return true;
    else if (sz(a) < sz(b)) return false;
    else {
        rep(i, 0, sz(a)) {
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
    }
    return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int a; cin >> a;
        val[num[a]] = max(val[num[a]], a);
    }

    vi digits;
    rep(i, 0, 10) {
        if (val[i]) {
            digits.push_back(val[i]);
        }
    }

    rep(i, 0, n - 1) {
        if (i != 0 && sz(dp[i]) == 0) continue;
        for (auto j : digits) {
            if (j >= last[i] && i + num[j] <= n) {
                char si = '0' + j;
                string news = si + dp[i];
                if (comp(news, dp[i + num[j]])) {
                    dp[i + num[j]] = news;
                    last[i + num[j]] = j;
                }
            }
        }
    }


    cout << dp[n];
}
