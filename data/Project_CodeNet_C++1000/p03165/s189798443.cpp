#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int slen = s.size();
    int tlen = t.size();
    
    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1, 0));
    
    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= tlen; j++) {
            if (s.at(i - 1) == t.at(j - 1)) {
                dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
            }
            else {
                dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
            }
        }
    }
  
    int length = dp.at(slen).at(tlen);
    int i = slen;
    int j = tlen;
    string ans = "";

    while (length > 0) {
        if (s.at(i - 1) == t.at(j - 1)) {
            ans = s.at(i - 1) + ans;
            length--;
            i--;
            j--;
        }
        else if (dp.at(i).at(j) == dp.at(i - 1).at(j)) {
            i--;
        }
        else { //dp.at(i).at(j) == dp.at(i).at(j - 1)
            j--;
        }
    }

    cout << ans << endl;
}