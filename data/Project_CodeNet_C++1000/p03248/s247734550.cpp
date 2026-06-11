#include <bits/stdc++.h>
using namespace std;
int INF = 1e9+7;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] == '0' || s[n-1] == '1')
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n-2; i++)
    {
        if(s[i] != s[n-i-2])
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << "1 2" << endl;
    cout << "2 3" << endl;
    int pos = 2;
    for(int i = 1; i < n-2; i++)
    {
        if(s[i] == '1')
        {
            pos = i + 2;
        }
        cout << pos << " " << i+3 << endl;
    }
}
