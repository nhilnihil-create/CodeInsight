#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int)(3e5 + 5);
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e9 + 11);

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < (int)s.size(); i += n)
        cout << s[i];
    return 0;
}
