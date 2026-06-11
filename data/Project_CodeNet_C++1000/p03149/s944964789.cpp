#include<bits/stdc++.h>

using namespace std;

long long a1, a2, a3, a4, a[15];
string s;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a1 >> a2 >> a3 >> a4;
    a[a1] = 1;
    a[a2] = 1;
    a[a3] = 1;
    a[a4] = 1;

    if(a[1] && a[9] && a[7] && a[4]) cout << "YES";
    else cout << "NO";
    return 0;

}
