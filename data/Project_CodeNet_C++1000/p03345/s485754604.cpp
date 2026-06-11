#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    ull k;
    cin>>a>>b>>c>>k;
    if(k%2==0)
        cout<<a-b<<endl;
    else
        cout<<b-a<<endl;
    return 0;
}