#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()

const int d5 = 100100;
vector<int> edge[d5],num,res;
int cnt=0;
void dfs(int x,int p){
    for(auto it:edge[x]){
        if(res[it]!=-1||p==it)continue;
        dfs(it,x);
    }
    res[x]=num[cnt];
    cnt++;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    num.resize(n);
    res.resize(n,-1);
    for(int i=0;i<n;i++)cin>>num[i];
    sort(All(num));
    res[0]=num[n-1];
    dfs(0,0);
    int ans=0;
    for(int i=0;i<n-1;i++)ans+=num[i];
    cout<<ans<<endl;
    for(int i=0;i<n;i++)cout<<res[i]<<' ';
    cout<<endl;
}