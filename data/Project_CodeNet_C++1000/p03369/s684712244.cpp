#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    int x = 700;
    string s;
    cin >> s;
    if(s[0] == 'o')
        x += 100;
    if(s[1] == 'o')
        x += 100;
    if(s[2] == 'o')
        x += 100;
    cout << x << endl;
    return 0;
}
