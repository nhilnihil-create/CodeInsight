#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,l,r,d,fa[200001],ra[200001],diff_weight[200001];
ll find(ll x){
    if(fa[x]==x)return x;
    ll xx=find(fa[x]);
    diff_weight[x]+=diff_weight[fa[x]];
    return fa[x]=xx;
}
ll weight(ll x){
    find(x);
    return diff_weight[x];
}
bool uni(ll x,ll y,ll w){
    w+=weight(x),w-=weight(y);
    x=find(x);
    y=find(y);
    if(x==y)return false;
    if(ra[x]<ra[y]){swap(x,y);w=-w;}
    fa[y]=x;
    if(ra[x]==ra[y])ra[x]++;
    diff_weight[y]=w;
    return true;
}
int main(void){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++){
        cin>>l>>r>>d;
        if(find(l)!=find(r))uni(l,r,d);
        else{
        if(weight(r)-weight(l)!=d){cout<<"No"<<endl;return 0;}
        }
    }
    cout<<"Yes"<<endl;
}
