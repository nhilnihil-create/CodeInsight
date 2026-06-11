//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n,k,cnt1=0;
    string s;
    cin>>s>>k;
   for(i=0;s[i];i++)
    {
        if(s[i]=='1') cnt1++;
        else break;
    }
    if(cnt1<k){
        cout<<s[cnt1]<<endl;
    }
    else
        cout<<1<<endl;
    return 0;
}



