#include <bits/stdc++.h>
using namespace std;

int n;
int cur;
int ways[200005];
int prevocc[200005];
int prevpos[200005];
int ans;

int dp(int pos){
    if (ways[pos]!=-1) return ways[pos];
    if (pos==0 || pos == -1 ) return 1;
    if (prevocc[pos]==-1 || prevocc[pos] == pos-1) return ways[pos] = (dp(pos-1) % 1000000007);
    return ways[pos] = ((dp(pos-1) + dp(prevocc[pos]))%1000000007);
}

int main(){
memset(prevpos,-1,sizeof(prevpos));
memset(prevocc,-1,sizeof(prevocc));
memset(ways,-1,sizeof(ways));
scanf("%d",&n);
for (int x = 0; x<n; x++){
    scanf("%d",&cur);
    if (prevpos[cur]!=-1){
        prevocc[x] = prevpos[cur];
    }
    prevpos[cur] = x;

}
printf("%d",dp(n-1));
}
