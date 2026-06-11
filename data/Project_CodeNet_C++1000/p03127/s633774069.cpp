/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,s=0;
    cin>>n;
    ll l1[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        if(i==1)m=l1[i];
        else m=__gcd(m,l1[i]);
    }
    cout<<m;
}
