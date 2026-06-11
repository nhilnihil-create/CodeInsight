#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N,K;
ll A[101010];
ll i, j, k,ans;
int main(){
    scanf("%lld%lld", &N, &K);
    
    fornum(i,0,N){
        scanf("%lld", &A[i]);
    }

    printf("%lld\n", (N - 2) / (K - 1) + 1);

    return 0;
}