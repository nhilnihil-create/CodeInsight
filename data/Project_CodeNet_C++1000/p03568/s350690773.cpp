#include<bits/stdc++.h>

int n, a[10];

int dfs(int cnt, int mlt){
        if(cnt==n) return mlt%2==0;
        int ret = 0;
        for(int i=-1; i<2; i++){
                ret += dfs(cnt+1, mlt*(a[cnt]-i)%2);
        }
        return ret;
}

int main(){
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        printf("%d\n", dfs(0, 1));
}