#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> nums;
    int now = 1;
    int cnt = 0;
    rep(i,n) {
      if (s[i]-'0' == now) cnt++;
      else {
        nums.push_back(cnt);
        now ^= 1;
        cnt = 1;
      } 
    }
    nums.push_back(cnt);
    if (nums.size()%2 == 0) nums.push_back(0);
    int l = 0, r = 0;
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      int nextleft = i, nextright = min(i+k*2+1, (int)nums.size());
      while (l < nextleft) {
        tmp -= nums[l];
        l++;
      }
      while (r < nextright) {
        tmp += nums[r];
        r++;
      }
      ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}