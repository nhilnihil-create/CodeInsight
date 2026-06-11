#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define line cout<<"----------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll mx=200009;
int ara[mx]; 
int pre[mx],suf[mx]; 
int main()
{
    int n; 
    cin>>n; 
    for(int i=1;i<=n;i++) 
    {
        cin>>ara[i]; 
        pre[i]=__gcd(pre[i-1],ara[i]);
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=__gcd(suf[i+1],ara[i]);
    }
    int maxi=0; 
    for(int i=1;i<=n;i++)
    {
        maxi=max(maxi,__gcd(pre[i-1],suf[i+1]));
    }
    cout<<maxi<<endl; 
    
}
