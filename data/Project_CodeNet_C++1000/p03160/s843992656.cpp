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
    int N; cin>> N;
    vector<int> h (N);
    forin(h);

    vector<int> dp(N, 1e9);
    dp[0] = 0;

    for(int i = 1; i < N; i++){
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if(i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout<< dp[N - 1] << endl;
}