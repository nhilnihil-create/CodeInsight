#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int v[100005];
int c1[100005],c2[100005];
int om,em,os,es;
int com,cem,Cos,ces;
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(i%2==1) c1[v[i]]++;
        else c2[v[i]]++;
    }
    for(int i=1;i<=n;i=i+2){
        if(com<=c1[v[i]]&&v[om]!=v[i]){
            com=c1[v[i]];
            om=i;
        }
    }
    for(int i=2;i<=n;i=i+2){
        if(cem<=c2[v[i]]&&v[em]!=v[i]){
            cem=c2[v[i]];
            em=i;
        }
    }
    for(int i=1;i<=n;i=i+2){
        if(Cos<=c1[v[i]]&&v[os]!=v[i]&&v[om]!=v[i]){
            Cos=c1[v[i]];
            os=i;
        }
    }
    for(int i=2;i<=n;i=i+2){
        if(ces<=c2[v[i]]&&v[es]!=v[i]&&v[em]!=v[i]){
            ces=c2[v[i]];
            es=i;
        }
    }
    //cout<<v[om]<<" "<<v[os]<<" "<<v[em]<<" "<<v[es]<<endl;
    if(v[om]!=v[em]){
        cout<<n-c1[v[om]]-c2[v[em]]<<endl;
    }else{
        cout<<min(n-c1[v[os]]-c2[v[em]],n-c1[v[om]]-c2[v[es]])<<endl;
    }

}

