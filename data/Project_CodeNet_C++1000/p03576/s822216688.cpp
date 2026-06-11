#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 5000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, K; cin >> N >> K;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<ll> X, Y;
    for (int i = 0; i < N; i++) {
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }
    sort(ALL(X));
    sort(ALL(Y));
    X.erase(unique(ALL(X)), X.end());
    Y.erase(unique(ALL(Y)), Y.end());

    int L = X.size();
    int M = Y.size();
    ll ans = INF;
    int k, l, cnt;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            if(i == j) continue;
            k = 0;
            l = 1;
            while(l < M){
                cnt = 0;
                for (int m = 0; m < N; m++) {
                    if(x[m] >= X[i] && x[m] <= X[j] && y[m] >= Y[k] && y[m] <= Y[l]){
                        cnt++;
                    }
                }
                if(cnt >= K){
                    ans = min(ans, (X[j] - X[i]) * (Y[l] - Y[k]));
                    k = k + 1;
                }
                else{
                    l = l + 1;
                }
            }
        }       
    }
    // for (int i = 0; i < L; i++) {
    //     printf("%lld\n", X[i]);
    // }
    // for (int i = 0; i < M; i++) {
    //     printf("%lld\n", Y[i]);
    // }
    printf("%lld\n", ans);

}