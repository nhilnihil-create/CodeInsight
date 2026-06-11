#include<cstdio>
#include<cstring>
int f[2][16005];
int x[8005],y[8005];
char s[8005];

void getReach(int n,int a[],int start){
    int offset = 8000;
    for(int i = -8000; i <= 8000; i++) f[0][i+offset] = 0;
    f[0][start+offset] = 1;
    for(int i = 1; i <= n; i++){
        int v = i%2; int u = !v;
        int step = a[i];
        for(int j = -8000; j <= 8000; j++){
            f[v][j+offset] = 0;
            int last = j-step;
            if(last>=-8000) f[v][j+offset] |= f[u][last+offset];
            last = j+step;
            if(last<=8000) f[v][j+offset] |= f[u][last+offset];
        }
    }
}

int main(){
    int tx,ty;
    scanf("%s%d%d",s+1,&tx,&ty);
    int n = strlen(s+1);
    int p = 1, baseX = 0;
    while(p<=n && s[p]=='F') p++, baseX++;
    int sizeX = 0, sizeY = 0; int direct = 0; // 0 for x
    while(p<=n){
        if(s[p]!='F'){
            direct = !direct;
            p++;
        }
        else{
            int np = p;
            while(np+1<=n && s[np+1]=='F') np++;
            int step = np-p+1;
            if(!direct) x[++sizeX] = step;
            else y[++sizeY] = step;
            p = np+1;
        }
    }
    int ok = 1;
    getReach(sizeX,x,baseX);
    int offset = 8000;
    if(f[sizeX%2][tx+offset]==0) ok = 0;
    getReach(sizeY,y,0);
    if(f[sizeY%2][ty+offset]==0) ok = 0;
    if(ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}
