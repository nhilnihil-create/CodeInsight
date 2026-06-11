#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    ll N,ans = 0;
    cin >> N;
    vector< P > A(N),B(N);
    rep(i,N){
        int a,b;
        cin >> a >> b;
        A[i] = P(b,a);
        B[i] = P(a,b);
    }
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    vector<ll> X(N+1),Y(N+1);
    rep(i,N){
        X[i+1] = X[i] + (A[i].first * -2);
        Y[i+1] = Y[i] + (B[i].first * 2);
    }
    rep(i,N){
        for(int j = -1;j <= 1;j++){
            if(i + j + 1 < 0 || i + j + 1 >= N)continue;
            ll num = X[i+1] + Y[i + j + 1];
            ans = max(ans, num);
        }
    }
    cout << ans << endl;
}