// https://atcoder.jp/contests/abc109/tasks/abc109_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<string> s;
    string p;
    cin >> p;
    s.insert(p);
    for (int i = 0; i < n - 1; i++)
    {
        string w;
        cin >> w;
        if (s.find(w) == s.end()) // ない
        {
            if (p[p.size() - 1] == w[0])
            {
                s.insert(w);
                p = w;
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
