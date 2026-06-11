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
    ll n;
    cin>>n;
    ll a=0,b,s=0;
    for(int i=1;i<=n;i++){
        cin>>b;
        s+=b;
        a=max(a,b);
    }
    cout<<s-(a/2)<<endl;
}
