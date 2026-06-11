#include<bits/stdc++.h>
#define init ios::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
using namespace std;
 
//  =========     /\       /|    |====/|
//      |        /  \       |    |   / |
//      |       /____\      |    |  /  |
//      |      /      \     |    | /   |
//  ========= /        \  =====  |/====|  
//  code

struct data{
    int w,s,v;
};

bool com(data d1,data d2){
    return (d1.w + d1.s < d2.w + d2.s);
}
int main(){
    init;
    const int SIZE = 2e4 + 5;
    long long int N,i,j,k,l;
    cin>>N;
    long long int dp[SIZE][N+1];
    vector<data> v(N+1);
    memset(dp,0,sizeof(dp));

    for(i=1;i<=N;i++){
        data *d = new data;
        cin>>d->w>>d->s>>d->v;
        v[i] = *d;
    }

    sort(v.begin(),v.end(),com);
    for(i = 1; i <= N; i++){
        for(j = v[i].s + v[i].w;j >= 0; j--){
            if(j >= v[i].w)
                dp[j][i] = max(dp[j][i-1] , dp[j-v[i].w][i-1] + v[i].v);
            else dp[j][i] = max(dp[j][i] , dp[j][i-1]);
        }
    }
    k = -1;
    for(i=0;i <= 2e4+4;i++){
        k = max(k , dp[i][N]);
    }
    cout<<k<<endl;
    return 0;
}