#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+5;

int n;
double a[N];
bool vis[N][N];
double mem[N][N];

double go(int idx , int cnt){
    if(idx == n + 1){
        return (cnt == 0);
    }
    if(vis[idx][cnt])
        return mem[idx][cnt];
    double c1 = 0;
    if(cnt)
        c1 = go(idx + 1 , cnt - 1) * a[idx];
    double c2 = go(idx + 1 , cnt) * (1.0 - a[idx]);
    vis[idx][cnt] = 1;
    return mem[idx][cnt] = c1 + c2;
}

int main(){
    scanf("%d " , &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf" , &a[i]);
    }
    double ans = 0;
    for(int i = n / 2 + 1; i <= n; i++)
        ans += go(1 , i);
    printf("%.10lf\n" , ans);
}
