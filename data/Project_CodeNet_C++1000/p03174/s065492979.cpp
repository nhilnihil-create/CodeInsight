#include <bits/stdc++.h>

using namespace std;

const int N = 21;

const int mod = 1e9+7;

int n;
int yes[N][N];
int mem[N][1 << N];

int go(int idx , int msk){
    if(idx == n)
        return 1;
    int &ret = mem[idx][msk];
    if(~ret)
        return ret;
    ret = 0;
    for(int i = 0; i < n; i++){
        if(msk & (1 << i))
            continue;
        if(yes[idx][i]){
            ret = (go(idx + 1 , msk ^ (1 << i)) + ret) % mod;
        }
    }
    return ret;
}

int main(){
    scanf("%d" , &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            scanf(" %d" , &x);
            yes[i][j] = x;
        }
    }
    memset(mem , -1 , sizeof mem);
    printf("%d\n" , go(0 , 0));
}
