//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    string as;
    cin >> as;
    int n = as.size();

    int ans = 0;
    rep(i, n) {
        if(as[i] == '0') ans++;
    }

    ans = max(ans, n-ans);

    cout << 2*n-2*ans << endl;
}