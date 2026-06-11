#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,x=0;
    cin>>n;
    map<string,ll>s;
    string a[101],b[101];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]++;
    }cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i];
        s[b[i]]--;
    }
    for(int i=1;i<=n;i++){
        x=max(x,s[a[i]]);
    }
    cout<<x;
}
