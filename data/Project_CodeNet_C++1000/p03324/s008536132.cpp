#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll d ,n;
    cin >> d >> n;
    if(d == 0) 
    {
        if(n<=99) cout << n << endl;
        else cout << n+1 << endl;
    } 
    else if (d == 1) 
    {
        if(n<=99) cout << n*100 << endl;
        else cout << (n+1)*100 << endl;
    } 
    else 
    {
        if(n<=99) cout << n*10000 << endl;
        else cout << (n+1)*10000 << endl;
    }
    return 0;
}