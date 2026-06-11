#include <bits/stdc++.h>
#define endl '\n';

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;

    if ((n + 1) / 2 >= k) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;

    return 0;
}
