#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    char prev = ' ';
    bool ok = true;
    set<string> s;
    for(int i = 0; i < n; i++)
    {
        string w;
        cin >> w;
        if(i > 0)
        {
            if(w[0] != prev || s.count(w))
                ok = false;
        }
        s.insert(w);
        prev = w[w.size() - 1];
    }

    cout << (ok ? "Yes" : "No");

    return 0;
}
