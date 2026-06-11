#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sz = s.size();
    if(s[0] != 'A') return cout << "WA\n", 0;
    int cnt = 0;
    for(int i = 1; i < sz; ++i)
    {
        if(isupper(s[i]))
        {
            if(i == 1 || i == sz - 1 || s[i] != 'C') return cout << "WA\n", 0;
            ++cnt;
        }
    }
    if(cnt != 1) return cout << "WA\n", 0;
    cout << "AC\n";
}