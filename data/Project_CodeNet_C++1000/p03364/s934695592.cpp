#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

bool check(int r, int c, vector<string>& strs, int n) { // O(n*3)
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if (strs[r+i][c+j] != strs[r+j][c+i])
                return false;
        }
    }
    return true;
}
int main() {
    int n, ans = 0;
    cin >> n;
    vector<string> strs;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        strs.push_back(s+s);
    }
    for(int i = 0; i < n; i++) {
        if (check(0, i, strs, n)) {
            ans += n;
        }
    }
    cout << ans << endl;
    return 0;
}


