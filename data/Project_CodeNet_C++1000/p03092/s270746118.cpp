#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)
#define INF (ll)1e15
ll N,A,B;
pll pp[101010];
ll dp[5050][10101],ans;
ll i, j;
ll aaa(const ll& a,const ll& b ){
    return a - 1 == b * 2 ? 0 : a - 1 < b * 2 ? B : A;
}

int main(){
    scanf("%lld%lld%lld", &N,&A,&B);
    fornum(i,0,N){
        ll p;
        scanf("%lld", &p);
        pp[i] = {p,i};
    }
    sort(pp, pp + N);
    fornum(i,0,N){
        ll minn = INF;
        fornum(j,0,N*2+1){
            if(j%2){
                dp[i + 1][j] = minn + aaa(j, pp[i].second);
                minn = min(dp[i][j],minn);

            }else{
                minn = min(dp[i][j],minn);
                dp[i + 1][j] = minn + aaa(j, pp[i].second);
            }
        }
    }
    ans = INF;
    fornum(i,0,N*2+1){
        ans = min(ans, dp[N][i]);
    }
    printf("%lld", ans);

    return 0;
}