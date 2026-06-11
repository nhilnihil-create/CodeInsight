#include<cstdio>
#include<algorithm>
int maxn[500005][20][2];
int a[500005];

void upDate(int& u,int &v,int x,int y){
    int b[5];
    b[0] = u, b[1] = v, b[2] = x, b[3] = y;
    std::sort(b,b+4);
    u = b[3], v = b[2];
}

int max(int a,int b){ return a>b?a:b; }

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < (1<<n); i++) scanf("%d",&a[i]);
    for(int i = 0; i < (1<<n); i++){
        maxn[i][0][0] = a[i], maxn[i][0][1] = 0;
        for(int j = 1; j <= n; j++){
            maxn[i][j][0] = maxn[i][j-1][0], maxn[i][j][1] = maxn[i][j-1][1];
            if(i&(1<<(j-1))){
                int last = i^(1<<(j-1));
                upDate(maxn[i][j][0],maxn[i][j][1],maxn[last][j-1][0],maxn[last][j-1][1]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < (1<<n); i++){ 
        ans = max(ans,maxn[i][n][0]+maxn[i][n][1]);
        printf("%d\n",ans);
    }
    return 0;
}
