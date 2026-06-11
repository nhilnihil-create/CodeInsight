#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> n(4);
    vector<int> a = { 1, 9, 7, 4 };

    for (int i = 0; i < n.size(); i++)
    {
        cin >> n[i];
    }
    
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == n[i])
            {
                a.erase(a.begin() + j);
                break;
            }
            if (j == a.size() - 1)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}