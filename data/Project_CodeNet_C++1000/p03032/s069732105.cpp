#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n)cin >> v[i];

    int ans = 0;
    rep(l, min(n, k) + 1){
        rep(m, l + 1){
            vector<int> j;
            rep(x, m)j.push_back(v[x]);
            rep(x, l - m)j.push_back(v[n-1-x]);
            sort(j.begin(), j.end(), greater<int>());
            int s = j.size();
            rep(x, min(k - l, s)){
                if(j[j.size()-1] < 0)j.pop_back();
                else break;
            }
            int sum = 0;
            rep(x, j.size())sum += j[x];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}