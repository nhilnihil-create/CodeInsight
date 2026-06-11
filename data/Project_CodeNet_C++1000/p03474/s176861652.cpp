#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b, c=0, ec = 0;
    string s;
    cin >> a >> b >> s;
    for(int i=0; i<=(a+b); i++)
    {
        if(s[a] == '-') ec = 1;
        if(s[i] == '-') c++;

    }
    if((c == 1) && (ec == 1)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}