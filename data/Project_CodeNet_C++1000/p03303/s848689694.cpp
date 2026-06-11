#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int w;
    cin >> w;
    int n = s.size();
    for(int i = 0; i < n; i += w)
        cout << s[i];

    return 0;
}
