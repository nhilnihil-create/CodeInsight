#include <iostream>
using namespace std;

#include <vector>
int main(){
    int n; cin >> n;
    vector<int> high(n),dp(n);
    for(int i=0; i<n; i++) cin >> high.at(i);
    dp.at(0)=0;
    dp.at(1)=abs(high.at(0)-high.at(1));
    for(int i=2; i<n; i++) {
        dp.at(i)=min(dp.at(i-1)+abs(high.at(i-1)-high.at(i)),dp.at(i-2)+abs(high.at(i-2)-high.at(i)));
    }
    printf("%d\n",dp[n-1]);
}