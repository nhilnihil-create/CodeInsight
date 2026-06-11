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
    
    long long i, j, k, n, m, t, x, y, z, s=9999, c=999999999999, l;
    cin >> n >> t;
    while(n--)
    {
        cin >> x >> y;
        if(y<=t && x<s)
            s=x;
    }
    if(s!=9999)
        cout << s << endl;
    else 
        cout << "TLE\n";
}
