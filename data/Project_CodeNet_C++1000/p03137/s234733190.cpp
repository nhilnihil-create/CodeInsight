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
    ll n,k;
    cin>>k>>n;
    ll l1[n+2];l1[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }if(k>=n){cout<<0;return 0;}
    sort(l1+1,l1+n+1);
    vector<ll>v;
    for(int i=1;i<n;i++){
        v.push_back(l1[i+1]-l1[i]);
    }
    sort(v.begin(),v.end(),greater<int>());
    ll s=0;
    for(int i=k-1;i<n;i++){
        s+=v[i];
    }
    cout<<s;
}
