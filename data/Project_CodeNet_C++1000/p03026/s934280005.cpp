#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
vector<int> G[N];
int ea[N],eb[N],d[N],e[N],c[N];
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        d[x]++;
        d[y]++;
        G[x].push_back(y);
        G[y].push_back(x);
        ea[i] = x, eb[i] = y;
    }
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    sort(c+1, c+1+n);
    int Min,id;
    for(int i=1;i<n;i++){
        Min = 1e9;
        for(int j=1;j<=n;j++){
            if(d[j] > 0 && d[j] < Min){
                Min = d[j];
                id = j;
            }
        }
        e[id] = c[i];
        d[id]--;
        for(int j=0;j<G[id].size();j++){
            d[G[id][j]]--;
        }
    }
    for(int i=1;i<=n;i++){
        if(e[i] == 0){
            e[i] = c[n];
            break;
        }
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans += min(e[ea[i]], e[eb[i]]);
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)printf("%s%d", (i==1 ? "" : " "), e[i]);
}
