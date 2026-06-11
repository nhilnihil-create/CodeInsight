#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> nums;
    int now = 1;
    int cnt = 0;
    rep(i, n){
        if(s[i] - '0' == now) cnt++;
        else{
            nums.push_back(cnt);
            now = 1 - now;
            cnt = 1;
        }
    }
    nums.push_back(cnt);
    if(now == 0) nums.push_back(0);
    
    if(2 * k + 1 >= nums.size()){
        cout << n << endl;
        return 0;
    }
    int memo = 0;
    rep(i, 2 * k + 1) memo += nums[i];
    int ans = memo;
    for(int i = 0; i < nums.size() - 2 * k - 1; i += 2){
        memo += nums[2 * k + 1 + i] + nums[2 * k + 2 + i];
        memo -= nums[i] + nums[i+1];
        ans = max(ans, memo);
    }
    cout << ans << endl;
    return 0;
}