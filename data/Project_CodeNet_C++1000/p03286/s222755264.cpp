#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    while(n != 0){
        int mod = n % -2;
        if(mod < 0){
            mod *= -1;
            n -= 2;
        }
        n /= -2;
        ans.push_back(mod);
    }
    reverse(ans.begin(), ans.end());
    rep(i, ans.size())cout << ans[i];
    cout << endl;
}