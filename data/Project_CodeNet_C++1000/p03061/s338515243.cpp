#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, a[100009], l[100009], r[100009], ans, g;
int main()
{
    IO
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        l[i]=__gcd(a[i],l[i-1]);
    }
    for(int i=n; i>=1; i--)
    {
        ans=max(ans,__gcd(g,l[i-1]));
        g=__gcd(g,a[i]);
    }
    cout<<ans;
}
