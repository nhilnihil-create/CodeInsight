#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<long long> vecll;
typedef vector<unsigned long long> vecull;

string s;

int main(void) {
    cin >> s;

    int l = 0;
    int r = s.size() - 1;

    int ans = 0;
    while (r - l > 0) {
        if (s[r] != s[l]) {
            if(s[r] == 'x') {
                s = s.insert(l, "x");
                ans++;
                r++;
            }
            else if (s[l] == 'x') {
                s = s.insert(r + 1, "x");
                ans++;
                r++;
            }
            else {
                ans = -1;
                break;
            }
        }

        r--;
        l++;
    }

    cout << ans << endl;

    return 0;
}