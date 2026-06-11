#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ar[500009],br[500009],cr[500009];
int main()
{
    ll a,b,c,i,j=0,k;
    string s;
    cin>>a;
    for(i=1; i<=a; i++)
    {
        cin>>ar[i];
    }
    //ar[a+1]=0;
    //ar[0]=0;
    for(i=0;i<=a+1;i++)
    {
        j=j+abs(ar[i]-ar[i-1]);
    }
    //cout<<j<<endl;
    for(i=1; i<=a; i++)
    {
        k=j+abs(ar[i-1]-ar[i+1])-abs(ar[i-1]-ar[i])-abs(ar[i]-ar[i+1]);
        cout<<k<<endl;
    }

}

