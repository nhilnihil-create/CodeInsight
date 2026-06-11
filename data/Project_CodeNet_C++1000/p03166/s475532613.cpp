#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
int N, M,a,b;
vvi ns;
ll dp[100000+3];

ll solve(int idx){

    ll &ret=dp[idx];
    if(~ret) return ret;

    ret=0;
    int sz=ns[idx].size();
    for(int i=0;i<sz;i++){
        ret =max(ret, 1+solve(ns[idx][i]));
    }

    return ret;

}

int main(){
    scanf("%d%d",&N,&M);
    ns=vvi(N);
    for(int i=0;i<N;i++)dp[i]=-1;
    while(M--){
        scanf("%d%d",&a,&b);
        a--, b--;
        ns[a].push_back(b);
    }

    ll mx=0;
    for(int i=0;i<N;i++){
        mx=max(mx, solve(i));
    }

    printf("%lld\n", mx);


    return 0;
}
