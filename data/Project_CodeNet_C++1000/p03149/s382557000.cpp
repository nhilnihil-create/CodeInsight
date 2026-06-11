#include<cstdio>
int cnt[10];

int main(){
    for(int i = 0; i < 4; i++){
        int u;
        scanf("%d",&u);
        cnt[u]++;
    }
    if(cnt[1]==1 && cnt[7]==1 && cnt[9]==1 && cnt[4]==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
