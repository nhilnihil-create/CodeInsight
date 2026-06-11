#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n,x=0;
int k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        x= __gcd(x,k);
    }
    cout<<x<<endl;
}