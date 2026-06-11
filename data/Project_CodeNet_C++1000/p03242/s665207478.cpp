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
    
    long long i, j, k, n, m, t, x, y, z, s=0, c=0, l;
    string a;
    cin >> a;
    for(i=0; i<a.size(); i++)
    {
        if(a[i]=='1')
            cout << "9";
        else if(a[i]=='9')
            cout << "1";
        else 
            cout << a[i];
    }
}
