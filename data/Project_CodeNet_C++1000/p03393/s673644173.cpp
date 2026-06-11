#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    string s;
    vector<int> used(26, 0);
    int cnt = 0;
    cin >> s;
    for(char c: s) {
        used[c-'a'] = 1;
        cnt += 1;
    }
    if (accumulate(used.begin(), used.end(), 0) == 26) {
        set<char> lg;
        string s2 = s;
        string ans = "";
        while(s2.size() > 0) {
            auto it = lg.upper_bound(s2.back());
            if (it != lg.end()) {
                string s3 = s2;
                s3.back() = *it;
                if (ans == "")
                    ans = s3;
                else
                    ans = min(ans, s3);
            }

            lg.insert(s2.back());
            s2.pop_back();
        }
        if (ans == "")
            cout << -1 << endl;
        else
            cout << ans << endl;
        return 0;
    } else {
        cout << s;
        for(int i = 0; i < 26; i++)
            if (used[i] == 0) {
                cout << char('a'+i) << endl;
                break;
            }
    }    
    return 0;
}
