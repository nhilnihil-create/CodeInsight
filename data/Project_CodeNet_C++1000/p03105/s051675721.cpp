#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    b/=a;
    if(b>=c)cout<<c;
    else cout << b;
}
