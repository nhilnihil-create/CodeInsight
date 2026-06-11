#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x=0,s2=0,k;
    cin>>n>>k;
    ll l1[n+1];
    map<ll,ll>m;
    map<ll,ll>m2;
    vector<ll>v;
    vector<ll>v2;
    set<ll>s;
    for(int i=1;i<=n;i++){
        cin>>x;m2[x]++;
        if(m[x]==0){
            m[x]=1;
            v.push_back(x);
        }
        s.insert(x);
    }
    if(k>=s.size())cout<<0<<endl;
    else{
        for(int i=0;i<v.size();i++){
            v2.push_back(m2[v[i]]);
        }
        sort(v2.begin(),v2.end());
        for(int i=0;i<s.size()-k;i++){
            s2+=v2[i];
        }
        cout<<s2<<endl;
    }
}
