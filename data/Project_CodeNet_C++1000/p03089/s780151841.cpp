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
    vector<int> b(n);
    rep(i, n)cin >> b[i];
    vector<int> ans;
    rep(i, n){
        int mx = 0;
        rep(j, n-i){
            if(b[j] == j+1){
                mx = j+1;
            }else if(b[j] > j+1){
                cout << -1 << endl;
                return 0;
            }
        }
        if(mx == 0){
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(mx);
        vector<int> c(n, 0);
        rep(j, n-i-1){
            if(j < mx-1)c[j] = b[j];
            else c[j] = b[j+1];
        }
        b = c;
    }
    rep(i, n)cout << ans[n-1-i] << endl;
}