#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    vector<int> a(3);
    cin >> n >> a[0] >> a[1] >> a[2];
    vector<int> l(n);
    rep(i, n)cin >> l[i];

    int mx = 1;
    rep(i, n)mx *= 4;
    int ans = 1001001001;
    rep(i, mx){
        vector<vector<int>> cnt(3);
        int x = i;
        rep(j, n){
            int k = x % 4;
            x /= 4;
            if(k == 0)cnt[0].push_back(j);
            else if(k == 1)cnt[1].push_back(j);
            else if(k == 2)cnt[2].push_back(j);
        }
        if(cnt[0].size() == 0 || cnt[1].size() == 0 || cnt[2].size() == 0)continue;
        int sum = 0;
        rep(j, 3){
            sum += 10 * (cnt[j].size() - 1);
            int asum = 0;
            rep(k, cnt[j].size()){
                asum += l[cnt[j][k]];
            }
            sum += abs(asum - a[j]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}