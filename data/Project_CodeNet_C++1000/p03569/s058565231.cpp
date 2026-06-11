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
    cin >> s;
    string s2;
    for(char c: s) {
        if (c != 'x') {
            s2 += c;
        }
    }
    int l = 0, r = s2.size()-1;
    while(l < r) {
        if (s2[l++] != s2[r--]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> cnt_x(s2.size()+1, 0);
    int cnt = 0, idx = 0;
    for(char c: s){
        if (c != 'x') {
            cnt_x[idx++] = cnt;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt > 0) {
        cnt_x[idx++] = cnt;
    }
    int ans = 0;
    l = 0, r = cnt_x.size()-1;
    while (l < r)
        ans += abs(cnt_x[l++]-cnt_x[r--]);
    cout << ans << endl;
    return 0;
}


