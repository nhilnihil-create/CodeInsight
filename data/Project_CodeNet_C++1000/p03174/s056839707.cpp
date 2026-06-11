#include <bits/stdc++.h>
using namespace std;
#define LL  long long
#define LIM 21
#define MOD 1000000007


int n, last, ara[LIM][LIM], dp[LIM][1<<LIM];
bool vis[LIM][1<<LIM];
bool chkBit(int val, int pos){return val&(1<<pos);}
int setBit(int val, int pos){return val|(1<<pos);}

LL f(int b, int mask){
    if(mask == last) return 1LL;
    if(vis[b][mask]) return dp[b][mask];
    vis[b][mask] = 1;
    LL ans = 0;
    for(int i = 0; i < n; i++){
        if(ara[b][i] && !chkBit(mask, i)){
            LL cur = f(b+1, setBit(mask, i));
            //cout<<"cur = "<<cur<<'\n';
            ans = (ans + cur)% MOD;
        }
    }
    return dp[b][mask] = ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    last = (1<<n) - 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) scanf("%d", &ara[i][j]);
    }
    LL ways = f(0, 0);
    printf("%lld\n", ways);
}


