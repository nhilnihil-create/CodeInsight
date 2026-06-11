#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,c,m;
    cin>>a>>b>>c;
    for(i=0;i<10;i++)
    {
        c=(a*c)-b;
        cout<<c<<endl;
    }
}