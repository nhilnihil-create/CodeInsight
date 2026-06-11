#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> b(m);
    rep(i, m)
        cin >> b.at(i);

    int cnt = 0;

    rep(i, n) {
        int a;
        int s = 0;

        rep(j, m) {
            cin >> a;

            s += a * b.at(j);
        }

        if (s + c > 0)
            cnt++;
    }

    cout << cnt << endl;
}
