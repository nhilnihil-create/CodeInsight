/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007
#define pi acos(-1.0)

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll s=0,x=0;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        s+=l1[i];x=max(x,l1[i]);
    }
    x<s-x?cout<<"Yes\n":cout<<"No\n";
}
