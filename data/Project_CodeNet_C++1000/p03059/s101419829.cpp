#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, i, sum=0, t=0;
    cin >> a >> b >> c;
    for(i=1;i<=20;i++)
    {
        t = t+a;
        if(t>c)
        {
            break;
        }
        sum = sum + (b*1);
    }
    cout << sum << endl;
    return 0;
}