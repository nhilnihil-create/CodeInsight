////////////////////////////////////
///     Please Give Me AC!!!     ///
////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N, K; cin>> N >> K;
    vector<int> h (N);
    forin(h);

    vector<int> dp(N + K, 1e9);
    dp[0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 1; j <= K; j++) {
            chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout<< dp[N - 1] << endl;
}