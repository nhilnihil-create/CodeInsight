#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

string s[3];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        set<char> ss;
        ss.insert(s[0][i]);
        ss.insert(s[1][i]);
        ss.insert(s[2][i]);
        if (ss.size() == 1) continue;
        if (ss.size() == 2) ans += 1;
        else ans += 2;
    }
    cout << ans << endl;
    return 0;
}



