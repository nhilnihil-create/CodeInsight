#include <bits/stdc++.h>
using namespace std;
int dp[100000]={0};
int main(){
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i=0;i<N;i++) cin >> h.at(i);
    dp[0]=0;
    dp[1]=abs(h.at(1)-h.at(0));
    for(int i=2;i<N;i++){
        dp[i] = min(dp[i-1]+abs(h.at(i)-h.at(i-1)), dp[i-2]+abs(h.at(i)-h.at(i-2)));
    }
    cout << dp[N-1] << endl;
    return 0;
}