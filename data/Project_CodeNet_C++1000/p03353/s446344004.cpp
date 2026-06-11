#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<string> ans;
    for(int i = 1; i <= k; i++) {
        int limit = n - i + 1;
        rep(j,limit) {
            string a = s.substr(j,i);
            ans.push_back(a);
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout << ans[k-1] << "\n";
    return 0;
}