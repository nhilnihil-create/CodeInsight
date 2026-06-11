#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string a = "keyence", b = "ecneyek";

int main() {
    string s; cin >> s;
    string t = s; reverse(t.begin(), t.end());

    int p = 0, q = 0;
    while (p<7&&s[p]==a[p]) p++;
    while (q<7&&t[q]==b[q]) q++;

    cout << (p+q>=7? "YES": "NO") << endl;
}
