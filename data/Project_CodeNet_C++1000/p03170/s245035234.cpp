#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#define ios   ios_base::sync_with_stdio(false);  cin.tie(0);    cout.tie(0);
typedef   long long int ll;
using namespace std;
const int M=1e9+7;
const int N=1e5+5;
#define fi first
#define se second
#define pb push_back
#define endl "\n"
bool check[N];
int main()
{
    ll n,k;cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;++i)
    cin>>a[i];
    for(ll i=a[0];i<=k;++i)
    {
        for(ll j=0;j<n && a[j]<=i;++j)
        {
            check[i]|=(!(check[i-a[j]]));
        }
    }
    if(check[k])
    cout<<"First";
    else
    cout<<"Second";
}