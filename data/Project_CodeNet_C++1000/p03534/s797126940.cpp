#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string S;
    cin >> S;
    int ca = 0, cb = 0, cc = 0;
    for (char c : S) {
        if (c == 'a')
            ca++;
        if (c == 'b')
            cb++;
        if (c == 'c')
            cc++;
    }

    int n[3];
    n[0] = ca;
    n[1] = cb;
    n[2] = cc;
    sort(n, n + 3);
    if ((n[0] == n[1] && n[2] - n[1] <= 1) || (n[1] - n[0] <= 1 && n[1] == n[2]))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
