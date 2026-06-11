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
    cin >> s;
    string dst = "AKIHABARA";
    if (s == dst) {
        cout << "YES" << endl;
        return 0;
    }
    int idx = 0;
    unordered_map<char, int> used;
    for(char c: dst) {
        if (idx < s.size() && c == s[idx]) {
            idx += 1;
        } else {
            used[c] += 1;
        }
    }
    
    if (idx == s.size() && used.size() == 1 && 
        used.count('A') > 0 && 
        used['A'] + s.size() == dst.size()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
