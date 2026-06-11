#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool revp2(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.first>b.first;}
bool revp3(const pair<ll,ll>&a,const pair<ll,ll>&b){if(a.first==b.first)return a.second<b.second;
return a.first>b.first;}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll n,m,x,s=0,s2=0;
    cin>>n>>m>>x;
    map<ll,ll>m2;
    ll l1[m+1];
    for(int i=1;i<=m;i++){
        cin>>l1[i];
        m2[l1[i]]=1;
    }
    ll a,b;
    a=abs(x);
    b=abs(x-n);
    //if(a<=b){
        for(int i=1;i<x;i++){
            if(m2[i])s++;
        }
        //cout<<s;
    //}
    //else{
        for(int i=x+1;i<n;i++){
            if(m2[i])s2++;
        }
        cout<<min(s,s2);
    //}
}
