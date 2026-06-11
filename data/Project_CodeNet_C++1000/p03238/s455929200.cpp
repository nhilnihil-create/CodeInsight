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
    cin >> n;
    if(n==1)
        cout << "Hello World\n";
    else if(n==2)
    {
        cin >> x >> y;
        cout << x+y << endl;
    }
}
