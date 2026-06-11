#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> w;
    int n;
    cin >> n;
    string prev;
    cin >> prev;
    w.push_back(prev);
    for (size_t i = 0; i < n - 1; i++)
    {
        string s;
        cin >> s;
        if (s[0] != prev[prev.length() - 1])
        {
            cout << "No" << endl;
            return 0;
        }
        if (std::find(w.begin(), w.end(), s) != w.end())
        {
            cout << "No" << endl;
            return 0;
        }
        prev = s;
        w.push_back(s);
    }
    cout << "Yes" << endl;

    return 0;
}