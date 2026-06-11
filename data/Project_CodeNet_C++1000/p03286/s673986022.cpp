//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n,ans=0;
    cin>>n;
   if(n==0) return cout<<0<<endl,0;
    string s="";


    while(n!=0)
    {
        if(n%(-2)==0)
        {
            s='0'+s;
            n/=(-2);
        }
        else{
            n=(n-1)/(-2);
            s='1'+s;
        }
    }

    cout<<s<<endl;




    return 0;
}



