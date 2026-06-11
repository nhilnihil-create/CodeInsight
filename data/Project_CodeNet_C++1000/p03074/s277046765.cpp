#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    int now = 1;
    int cnt = 0;
    vector<int> nums;
    rep(i,n) {
        if(s[i]-'0'==now) cnt++;
        else {
            nums.push_back(cnt);
            now = 1- now;
            cnt = 1;
        }
    }
    if(cnt!=0) nums.push_back(cnt);
    if(s[n-1]=='0') nums.push_back(0);

    vector<int> sums((int)nums.size()+1, 0);
    //累積和
    rep(i,nums.size()){
        sums[i+1] = sums[i] + nums[i];
    }

    int ans = 0;
    for(int l = 0; l < sums.size(); l+=2){
        int r = l + k*2 + 1;
        if(r >= sums.size()) r = sums.size()-1;
        ans = max(ans, sums[r]-sums[l]);
    }
    cout << ans << endl;
    return 0;
}
