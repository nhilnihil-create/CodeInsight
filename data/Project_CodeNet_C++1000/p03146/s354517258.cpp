#include<bits/stdc++.h>
using namespace std;
#define  mem(a,x) memset(a,x,sizeof(a));
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
//string s,p;
//vector<int>v;
//map<int,int>mp;
int main()
{
    ft
    int t,i,j,n,m,l=1,r;
    cin>>n;
    map<int,int>mp;
    mp[n]=1;
    while(1)
    {
        if(n%2==0)
        {
            n/=2;
        }
        else
        {
            n=3*n+1;
        }
        l++;
        if(mp[n]==1)
        {
            cout<<l<<"\n";
            return 0;
        }
        mp[n]=1;
    }
    return 0;
}

