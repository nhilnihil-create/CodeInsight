#include <bits/stdc++.h>
    using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0])
        cout << "YES";
    else
        cout << "NO";
    return  0;
}