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
    cin>>n>>m;map<ll,ll>f;
    for(int i=1;i<=n;i++){
        ll k,a;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a;f[a]++;
            if(i==n&&f[a]==n)s++;
        }
    }
    cout<<s;
}
