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
    ll n,i=1;
    cin>>n;
    map<ll,ll>m;m[n]=1;
    while(1){
        if(n&1)n=3*n+1;
        else n/=2;
        ++i;
        if(m[n]==1){
            cout<<i;return 0;
        }
        else m[n]=1;
    }
}
