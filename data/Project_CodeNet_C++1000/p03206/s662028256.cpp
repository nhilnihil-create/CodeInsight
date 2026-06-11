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
    cin >> x;
    if(x==25)
        cout << "Christmas\n";
    else if(x==24)
        cout << "Christmas Eve\n";
    else if(x==23)
        cout << "Christmas Eve Eve\n";
    else if(x==22)
        cout << "Christmas Eve Eve Eve\n";
}
