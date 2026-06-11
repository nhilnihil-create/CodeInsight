#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<bool> dp(k+1, false);
    vector<int> stones(n);
    for(int i=0;i<n;i++){ cin >> stones[i]; dp[stones[i]]=true; }
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-stones[j] > 0 && !dp[i-stones[j]]) dp[i]=true;
        }
    }
    //for(int i=1;i<=k;i++) cout << "stones: " << i << " winning: " << (bool)dp[i] << endl;
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}