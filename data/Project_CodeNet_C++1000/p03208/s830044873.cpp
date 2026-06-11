/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll n,k,s=1e18;
    cin>>n>>k;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    sort(l1+1,l1+n+1,greater<int>());
    for(int i=1;i<=n-k+1;i++){
        s=min(s,l1[i]-l1[i+(k-1)]);
    }
    cout<<s<<endl;
}
