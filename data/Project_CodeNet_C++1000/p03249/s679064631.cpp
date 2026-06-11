#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#define ll long long
#define pii pair<int,int>
#define MP make_pair
using namespace std;
ll n;
map<ll,int>rev;
struct node{ll d,siz,val;int id;}a[100005];
bool cmp(node x,node y){return x.d>y.d;}
int back[100005];
vector<pii>ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].d);
        a[i].siz=1;a[i].id=i;
        rev[a[i].d]=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) back[a[i].id]=i;
    for(int i=1;i<n;i++){
        if(n-2*a[i].siz<=0){puts("-1");return 0;}
        ll dd=a[i].d+2*a[i].siz-n;
        if(!rev[dd]){puts("-1");return 0;}
        int fa=rev[dd];
        ans.push_back(MP(min(fa,a[i].id),max(fa,a[i].id)));
        a[back[fa]].siz+=a[i].siz;
        a[back[fa]].val+=a[i].val+a[i].siz;
    }
    if(a[n].d!=a[n].val) return puts("-1"),0;
    sort(ans.begin(),ans.end());
    for(int i=0;i<n-1;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
