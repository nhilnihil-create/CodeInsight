#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    // 尺取法
    V<int> nums;
    int cnt = 1;
    if(s[0] == '0') nums.push_back(0);
    for(int i = 0; i < n; i++){
        if(s[i] == s[i + 1]) cnt++;
        else{
            nums.push_back(cnt);
            cnt = 1;
        }
    }
    if(s[n - 1] == '0') nums.push_back(0);

    int m = nums.size();
    int left = 0, right = 0;
    int ans = 0, tmp = 0;
    for(int i = 0; i < m; i+=2){
        int nleft = i;
        int nright = min(i + 2 * k + 1, m);
        while(nleft > left){
            tmp -= nums[left];
            left++;
        }
        while(nright > right){
            tmp += nums[right];
            right++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;


    return 0;
}
