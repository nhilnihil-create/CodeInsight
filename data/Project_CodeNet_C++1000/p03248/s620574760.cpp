#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
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
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] != s[n-2-i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    int now = 2;
    for(int i = 1; i < n-2; i++)
    {
        if(s[i] == '0')
        {
            cout << now << " " << i+3 << endl;
        }
        else
        {
            cout << i+2 << " " << i+3 << endl;
            now = i+2;
        }
    }
}
