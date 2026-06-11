#include <bits/stdc++.h>

using namespace std;

int n, x, y;
const int bias = 8005;
char str[8010];
int arr[2][8010];
bool can[2][16010];

bool solve(int arr[], int m, int x) {
    int i, j, s = 0;
    memset(can,0,sizeof(can));
    can[0][bias] = 1;
    sort(arr,arr+m);
    for (i=0;i<m;i++) {
        for (j=-s;j<=s;j++) {
            if (can[0][bias+j]) {
                can[1][bias+j+arr[i]]=can[1][bias+j-arr[i]]=1;
            }
        }
        s += arr[i];
        for (j=-s;j<=s;j++) {
            can[0][j+bias]=can[1][j+bias];
            can[1][j+bias]=0;
        }
    }
    return x>=-s&&x<=s&&can[0][x+bias];
}

int main() {
    scanf("%s",str); n = strlen(str);
    scanf("%d%d",&x,&y);
    int i=0;
    for (;str[i]=='F';i++);
    x-=i; int c = 0;
    for (;str[i];c++) {
        i++; int j=i;
        for (;str[i]=='F';i++);
        arr[(c+1)%2][c/2]=i-j;
    }
    if (solve(arr[0],c/2+1,x)&&solve(arr[1],c/2+1,y)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
