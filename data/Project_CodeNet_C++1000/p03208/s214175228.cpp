#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) 
{ 
    if(b==0) 
        return a; 
    return GCD(b, a%b);  
      
}

long long LCM(long long a, long long b)
{
    long long gcd=GCD(a,b);
     return (a*b)/gcd;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long i, j, k, n, m, t, x, y, z, s=999999999999, c=0, l;
    cin >> n >> k;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    for(i=0; i<=n-k; i++)
    {
        x=a[i+k-1]-a[i];
        if(x<s)
            s=x;
    }
    cout << s << endl;
}
