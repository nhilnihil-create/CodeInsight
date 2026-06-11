#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, cnt = 0; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] && b[i] != c[i] && a[i] != c[i]) cnt+=2;
        else if(a[i] == b[i] && b[i] == c[i]) cnt += 0;
        else cnt++;
    }
    cout << cnt << endl;
    return 0;
}