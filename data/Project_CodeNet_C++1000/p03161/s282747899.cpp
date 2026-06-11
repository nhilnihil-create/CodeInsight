#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n;
    cin >> k;

    vector<int> dp(n);
    vector<int> hs(n);
    cin >> hs[0];
    for (int i=1;i<n;++i){
        cin >> hs[i];
        int minv=INT_MAX;
        for (int j=max(i-k,0);j<i;++j) {
            minv=min(minv,dp[j]+abs(hs[j]-hs[i]));
        }
        dp[i]=minv;
    }
    cout << dp[dp.size()-1];
}