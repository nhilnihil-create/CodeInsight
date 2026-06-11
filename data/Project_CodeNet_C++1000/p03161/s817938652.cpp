#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
using V = vector<T>;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for(int i=m; i<n; i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = b - 1; i >= int(a); i--)

int main(){
    int N, K;
    cin >> N >> K;
    V<int> H(N);
    rep(i, N) cin >> H.at(i);

    V<ll> dp(N);
    dp.at(N-1) = 0;
    for(int i=N-2; i>=N-1-K && i>=0; i--) dp.at(i) = abs(H.at(N-1) - H.at(i));

    for(int i=N-2-K; i>=0; i--){
        ll min = 1000000000;
        for(int j=i+1; j<=i+K && j<N; j++){
            ll cost = dp.at(j) + abs(H.at(j) - H.at(i));
            if(cost < min) min = cost;
        }
        dp.at(i) = min;
    }
    
    cout << dp.at(0) << endl;
}