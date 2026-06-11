#include <iostream>
using namespace std;

#include <vector>
int main(){
    int n,k; cin >> n >> k;
    vector<int> high(n),dp(n);
    for(int i=0; i<n; i++) cin >> high.at(i);
    for(int i=1; i<n; i++){
        dp.at(i) = dp.at(i-1)+abs(high.at(i)-high.at(i-1));
        for(int j = max(0,i-k); j < i-1; j++) {
            dp.at(i) = min(dp.at(i),dp.at(j)+abs(high.at(i)-high.at(j)));
        }
    }
    printf("%d\n",dp[n-1]);
}