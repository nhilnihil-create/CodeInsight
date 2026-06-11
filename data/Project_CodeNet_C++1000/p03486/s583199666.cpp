#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<int>());
    if (s < t)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
