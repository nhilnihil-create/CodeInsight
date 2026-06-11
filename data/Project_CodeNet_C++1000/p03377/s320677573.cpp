#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int gatos, animais, posgatos;
    cin >> gatos >> animais >> posgatos;
    if (gatos > posgatos)
    {
        cout << "NO" << endl;
    }
    else if (gatos + animais < posgatos)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}