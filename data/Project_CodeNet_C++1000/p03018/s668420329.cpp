#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    string s;
    string trans;
    cin >> s;
    int n = s.size();
    vector<int> label(n, 0);
    for(int i = 0; i < n; i++) {
        if (s[i] == 'B' && (i+1 < n && s[i+1] == 'C')) {
            label[i+1] = 1;
        }
    }
    int valid_cnt = 0;
    ll ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if (label[i] == 1 || s[i] == 'A') {
            if (label[i] == 1) {
                valid_cnt += 1;
                i -= 1;
            } else if (s[i] == 'A') {
                ans += valid_cnt;
            }
        } else {
            valid_cnt = 0;
        }
    }
    cout << ans << endl;

    return 0;
}


