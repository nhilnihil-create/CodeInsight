#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
vector<int>a[110];
pair<int,int>ans[maxn];
int main(){
    int n,cnt=0,res=1,tot=0;
    scanf("%d",&n);
    if(n&1){
        res=0;
        a[++cnt].push_back(n);
    }
    for(int i=1;i<=n/2;i++){
        a[++cnt].push_back(i);
        a[cnt].push_back(n-i+res);
    }
    for(int i=1;i<cnt;i++){
        for(int j=0;j<a[i].size();j++){
            int u=a[i][j];
            for(int k=0;k<a[i+1].size();k++){
                int v=a[i+1][k];
                ans[++tot]=make_pair(u,v);
            }
        }
    }
    if(cnt>2){
        for(int i=0;i<a[1].size();i++){
            int u=a[1][i];
            for(int j=0;j<a[cnt].size();j++){
                int v=a[cnt][j];
                ans[++tot]=make_pair(u,v);
            }
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}