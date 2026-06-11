#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define mod 1e9+7
#define ll long long int
#define epsilon 1e-7

ll min(ll x, ll y){
    if(x<y)return x;
    return y;
}
char s[8001];
int xx[4001];
int yy[4001];
int dx[16001][4001];//dx[j][i]はi-1番目まででj-xmaxが実現するか
int dy[16001][4001];
int main(void){
    int x, y;
    scanf("%s", &s);
    scanf("%d %d", &x, &y);
    int fo = 1;
    int xxx = 0;
    int yyy = 0;
    int me = 0;
    for(int i = 0;s[i]!='\0';i++){
        if(s[i]=='F')me++;
        else{
            if(fo == 1){
                xx[xxx] = me;
                me = 0;
                fo = 2;
                xxx++;
            }else{
                yy[yyy] = me;
                me = 0;
                fo = 1;
                yyy++;
            }
        }
    }
    if(me!=0){
        if(fo == 1){
            xx[xxx] = me;
            me = 0;
            fo = 2;
            xxx++;
        }else{
            yy[yyy] = me;
            me = 0;
            fo = 1;
            yyy++;
        }
    }
    int xmax = 0;
    int ymax = 0;
    for(int i = 0;i < xxx;i++){
        xmax += xx[i];
        //printf("%d ", xx[i]);
    }
    //printf("\n");
    for(int i = 0;i < yyy;i++){
        ymax += yy[i];
        //printf("%d ", yy[i]);
    }
    //printf("\n");
    for(int i = 0;i < xxx + 1;i++){
        for(int j = 0;j < 2*xmax + 1;j++){
            dx[j][i] = 0;
        }
    }
    for(int i = 0;i < yyy + 1;i++){
        for(int j = 0;j < 2*ymax + 1;j++){
            dy[j][i] = 0;
        }
    }
    dx[xmax + xx[0]][1] = 1;
    dy[ymax][0] = 1;
    for(int i = 0;i < xxx;i++){
        for(int j = 0;j < 2*xmax + 1;j++){
            if(dx[j][i]){
                dx[j - xx[i]][i+1] = 1;
                dx[j + xx[i]][i+1] = 1;
            }
        }
    }
    for(int i = 0;i < yyy;i++){
        for(int j = 0;j < 2*ymax + 1;j++){
            if(dy[j][i]){
                dy[j - yy[i]][i+1] = 1;
                dy[j + yy[i]][i+1] = 1;
            }
        }
    }
    if(x + xmax < 0 || y + ymax < 0)printf("No\n");
    else if(dx[x+ xmax][xxx] && dy[y+ ymax][yyy])printf("Yes\n");
    else printf("No\n");
    return 0;
}