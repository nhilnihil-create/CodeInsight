#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    //0の個数と1の個数をカウントして配列に保存
    vector<int>nums;
    if(s[0] == '1') nums.push_back(0);
    int cur = 1;
    rep(i,n-1) {
        if(s[i] == s[i+1]) cur++;
        else {
            nums.push_back(cur);
            cur = 1;
        }
    }
    nums.push_back(cur);
    //累積和をとる
    int m = nums.size();
    vector<int>sum(m+1);
    sum[0] = 0;
    rep(i,m) sum[i+1] = sum[i] + nums[i];
    //区間の最大値を計算
    int ans = 0;
    for(int left = 0;left<m;left += 2) {
        int right = min(m-1,left+2*k-1);
        int tmp = sum[right+1] - sum[left-1];
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}