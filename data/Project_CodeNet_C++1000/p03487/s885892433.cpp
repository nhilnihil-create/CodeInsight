#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,s=0;map<ll,ll>m;
    cin>>n;
    set<ll>se;
    for(int i=1;i<=n;i++){
        cin>>a;
        m[a]++;
        se.insert(a);
    }
    for(auto it=se.begin();it!=se.end();it++){
        if(m[*it]>*it)s+=m[*it]-*it;
        else if(m[*it]<*it)s+=m[*it];
    }
    cout<<s<<endl;
}
