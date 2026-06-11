#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string a,b,c;
    for(int i=0;i<3;i++)
    {
        cin >> s;
        if(i==0) a = s[0];
        if(i==1) b = s[1];
        if(i==2) c = s[2];
    }
    cout << a << b << c << endl;
}
