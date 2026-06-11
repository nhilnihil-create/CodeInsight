#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
long long num[1000000];
int main()
{
    ll n,a,x=1e10,d=0,l=0;
    cin >> n;
    for (int i = 1; i <= n;++i)
    {
        cin >> num[i];
        a = abs(num[i]);
        d += a;
        if(num[i]<0)
        {
            ++l;
            
        }
        if(a<x)
        x = a;
    }
    if(l&1)
        cout << d - 2*x;
    else
        cout << d;
}