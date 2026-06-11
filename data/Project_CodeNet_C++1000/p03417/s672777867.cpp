#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vi;
vector<ll> :: iterator vt;
ll arr[200009];
int main()
{
    ll n,t,x,y,z,m,j,i,k,flag =0,maxi=LONG_LONG_MIN ,mini=LONG_LONG_MAX,sum=0,c=0;
    map<ll,ll>mp;
    map<ll,ll> :: iterator mt;
    string s, ss;
    cin>>n>>m;
    x=n*m;
    if(n==1 && m==1)
        cout<<1<<endl;
    else if(m==2 || n==2)
        cout<<0<<endl;
    else if( m == 1 )
    {
        cout<<n-2<<endl;
    }
    else  if(n == 1)
        cout<<m-2<<endl;
    else{
        cout<<m*n - m*2-n*2 +4<<endl;
    }


}

