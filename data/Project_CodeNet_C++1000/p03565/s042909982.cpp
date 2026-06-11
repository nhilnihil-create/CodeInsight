#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator
string s, t, res;
int n, m, j;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    string res = "~";
    for(int i=0; i<=n-m; ++i) {
        bool tmp = 1;
        string s2 = s;
        for(int j=0; j<m; ++j) {
            if(s[i+j] != '?' && s[i+j] != t[j])
                tmp = 0;
            s2[i+j] = t[j];
        }
        if(tmp) {
            replace(s2.begin(), s2.end(), '?', 'a');
            res = min(res, s2);
        }
    }
 
    if(res == "~")
        cout << "UNRESTORABLE" << endl;
    else
        cout << res << endl;
}

int main() {
    solve();
    return 0;
}