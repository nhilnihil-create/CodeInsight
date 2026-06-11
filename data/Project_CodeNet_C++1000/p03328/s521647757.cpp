#include<bits/stdc++.h>
using namespace std;
#define Mod(n) n % 1000000007
int main()
{
    int a,b,d;
    cin >> a >> b;
    d = b - a;
    int sum = 0;
    for(int i = 1;i < 1000;i++)
    {
        sum+=i;
        if(i == d)
            break;
    }
    cout << sum - b << endl;;
}