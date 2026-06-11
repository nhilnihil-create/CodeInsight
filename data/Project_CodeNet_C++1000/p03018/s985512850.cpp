#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

string replaceAll(string &replacedStr, string from, string to) {
    int pos = replacedStr.find(from);
    int toLen = to.length();
 
    if (from.empty()) {
        return replacedStr;
    }
 
    while ((pos = replacedStr.find(from, pos)) != string::npos) {
        replacedStr.replace(pos, from.length(), to);
        pos += toLen;
    }
    return replacedStr;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    replaceAll(s, "BC", "D");
    int N = s.size();
    int Anum = 0;
    int ans = 0;
    for (int i=0;i<N;i++){
        if (s[i] == 'A') Anum++;
        else if (s[i] == 'B') Anum = 0;
        else if (s[i] == 'C') Anum = 0;
        else {
            ans += Anum;
        }
    }
    cout << ans << "\n";
}