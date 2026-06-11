#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    vector<int> nums(3);
    rep(i,3) cin >> nums[i];
    sort(RALL(nums));
    int ans = 0;
    ans += nums[0] * 10 + nums[1];
    ans += nums[2];
    cout << ans << endl;
}