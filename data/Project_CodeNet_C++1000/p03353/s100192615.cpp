#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int k, n;
    cin >> k;
    n = s.size();

    vector<pair<char, int>> idx;
    rep(i, n){
        idx.push_back(make_pair(s[i], i));
    }
    sort(idx.begin(), idx.end());

    set<string> ans;
    char c = idx[0].first;
    char last = c;
    int cnt = 0;
    while(ans.size() < k || c == last){
        rep(i, k){
            int l = i + idx[cnt].second;
            if (l < n) {
                string sub = s.substr(idx[cnt].second, i + 1);
                ans.insert(sub);
            }
        }
        cnt++;
        last = c;
        c = idx[cnt].first;
    }
    
    cnt = 0;
    for (string sub : ans){
        cnt++;
        if(cnt == k) {
            cout << sub << endl;
            return 0;
        }
    }
}