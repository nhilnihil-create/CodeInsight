#include <bits/stdc++.h>
using namespace std;
string s;
int k;
vector<string> ans;

int main() {
    cin >> s >> k;
    int slen = s.length();
    for(int i = 0; i < slen; ++i) {
        for(int j = 1; j <= min(k, slen-i); ++j) {
            string now = s.substr(i, j);
            ans.push_back(now);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.at(k-1) << endl;
}