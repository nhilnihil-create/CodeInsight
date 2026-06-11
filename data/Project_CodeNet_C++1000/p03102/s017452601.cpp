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
    ll n,m,c,s=0;
    cin>>n>>m>>c;
    ll l1[m+1],l2[m+1];
    for(int i=1;i<=m;i++)cin>>l1[i];
    for(int j=1;j<=n;j++){ll x=0;
        for(int i=1;i<=m;i++){
            cin>>l2[i];
            x+=(l2[i]*l1[i]);
        }x+=c;
        if(x>0)s++;
    }
    cout<<s;
}
