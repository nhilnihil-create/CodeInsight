#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,d,e,f,g,h,i,j;

    cin >> a >> b;
    if (a == 1 && b == 1)
        {cout << 1 << endl;}
    else if (a == 1)
        {cout << b - 2 << endl;}
    else if (b== 1)
        {cout << a - 2 << endl;}
    else
        {cout << (b - 2)*(a - 2) << endl;}
    return 0;
}
