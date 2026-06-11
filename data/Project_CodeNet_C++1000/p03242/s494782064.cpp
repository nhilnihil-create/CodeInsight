#include <bits/stdc++.h>

using namespace std;

long long a,b,c,n;

int main()
{
    cin >> n;
    a = n/100;
    b = n/10 % 10;
    c = n%10;
    if(a==1) cout<<9;
    else cout<<1;

    if(b==1) cout<<9;
    else cout<<1;

    if(c==1) cout<<9;
    else cout<<1;


    return 0;
}
