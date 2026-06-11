#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,a,b,ch[10000],L[10000],ans,cnt;
vector<ll> v[10000];
void dfs(ll x){
    ch[x]=L[cnt];
    cnt++;
    for(ll y:v[x]){
        if(ch[y]==0){
            dfs(y);
        }
    }
    return ;
}
int main(void){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){cin>>L[i];ans+=L[i];}
    sort(L,L+n);
    ans-=L[n-1];
    reverse(L,L+n);
    dfs(0);
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        cout<<ch[i]<<" ";
    }
    cout<<endl;
}
