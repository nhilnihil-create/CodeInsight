#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool ans = true;
    cin >> n;
    string w[n];
    for (string &i : w)
        cin >> i;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (w[i] == w[j])
            {
                ans = false;
                break;
            }
        }
        if (w[i].at(w[i].size() - 1) != w[i + 1].at(0))
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}