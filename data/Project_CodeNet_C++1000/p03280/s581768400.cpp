#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  a,b,s;
    while(cin >> a >> b)
    {
        s = a*b;
        s-=(a+b-1);
        cout << s << endl;
    }
}
