#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define MAX 8004
using namespace std;
typedef long long ll;
bool dp[MAX][MAX*2];
int len,x,y,c1;
char route[MAX];
void update(int q){
    for(int i=0;i<MAX*2;i++) if(dp[c1][i]){
        int t1=i+q,t2=i-q;
        if(0<=t1&&t1<MAX*2) dp[c1+1][t1]=1;//printf("%d ",t1-MAX);
        if(0<=t2&&t2<MAX*2) dp[c1+1][t2]=1;//printf("%d ",t2-MAX);
    }
    printf("\n");
    c1++;
}
int main(){
    scanf(" %s %d %d",route,&x,&y);
    x+=MAX,y+=MAX;
    len=strlen(route);
    int i=0;
    dp[0][MAX]=1;
    for(;i<len;i++){
        int cnt;
        for(cnt=0;route[i]=='F';i++,cnt++);
        i++;
        for(cnt=0;route[i]=='F';i++,cnt++);
        update(cnt);
    }
    if(dp[c1][y]==0){
        printf("No\n");
        return 0;
    }
    for(int i=0;i<=c1;i++) for(int j=0;j<MAX*2;j++) dp[i][j]=0;
    for(i=0;route[i]=='F';i++);
    dp[0][MAX+i]=1,c1=0,i++;
    for(;i<len;i++){
        int cnt;
        for(cnt=0;route[i]=='F';i++,cnt++);
        i++;
        for(cnt=0;route[i]=='F';i++,cnt++);
        update(cnt);
    }
    if(dp[c1][x]==0){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}
