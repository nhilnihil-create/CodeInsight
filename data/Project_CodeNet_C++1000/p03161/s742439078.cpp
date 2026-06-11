#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin >> N >> K;
    vector<int> h(N);
    for(int i=0;i<N;i++) cin >> h.at(i);

    int dp[N];
    dp[0] = 0;
    for(int i=1;i<N;i++){
        int mi = 1001001001;
        for(int j=1;j<K+1;j++){
            if(i-j<0) break;
            int cost = abs(h.at(i) - h.at(i-j));
            mi = min(mi, dp[i-j]+cost);//dp[i]よりK以下だけ前の場所から移動するのにかかる最低合計コストを計算
        }
        dp[i] = mi;
    }
    cout << dp[N-1] << endl;
    return 0;
}