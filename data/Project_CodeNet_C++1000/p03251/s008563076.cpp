#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
ll N, M, X, Y;
ll i, j, k;
int main(){

    scanf("%lld%lld%lld%lld", &N, &M, &X, &Y);
    j = X;
    fornum(i,0,N){
        ll x;
        scanf("%lld", &x);
        j = max(j, x);
    }
    k = Y;
    fornum(i,0,M){
        ll y;
        scanf("%lld", &y);
        k = min(k, y);
    }
    if(j<k){
        printf("No War");
    }else{
        printf("War");
    }
    return 0;
}