#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N,M;
ll X[3][1111], Y[3][1111], Z[3][1111];
ll i, j, k;

ll ans;

void mxin(ll& a,ll b){
    if(a<b)
        a = b;
}


ll calc(ll* x,ll* y,ll* z){
    ll i, j;
    vector<ll> vv;
    fornum(i,0,N){
        vv.push_back(x[i] + y[i] + z[i]);
    }
    sort(vv.begin(), vv.end());
    ll a = 0;
    fornum(i,0,M){
        a += vv[N - 1 - i];
    }
    return a;
}


int main(){
    scanf("%lld%lld",  &N,&M);

    fornum(i,0,N){
        scanf("%lld%lld%lld", &X[0][i], &Y[0][i], &Z[0][i]);
        X[1][i] = -X[0][i];
        Y[1][i] = -Y[0][i];
        Z[1][i] = -Z[0][i];
    }
    fornum(i,0,8){
        mxin(ans, calc(X[(i & 1) == 0], Y[(i & 2) == 0], Z[(i & 4) == 0]));
    }

    printf("%lld\n", ans);
    return 0;
}
