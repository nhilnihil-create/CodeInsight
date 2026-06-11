#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b; cin >> a >> b;
    int cnt = 0;
    for (int i=a;i<=b;i++) {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        if (s==t) cnt++;
    }
    cout << cnt << endl;
}
