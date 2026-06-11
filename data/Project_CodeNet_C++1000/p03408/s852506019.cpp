#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;
    vector<string> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<string> moji;
    vector<int> mojic;
    for (int i = 0; i < n; i++) {
        if (!(any_of(moji.begin(), moji.end(), [&](string x) { return x == a[i]; }))) {
            moji.push_back(a[i]);
            mojic.push_back(count(a.begin(), a.end(), a[i]));
        }
    }
    for (int i = 0; i < moji.size(); i++) {
        mojic[i] -= count(b.begin(), b.end(), moji[i]);
    }

    int answer = *max_element(mojic.begin(), mojic.end());
    if (answer > 0) {
        cout << answer << endl;
    } else {
        cout << 0 << endl;
    }
}