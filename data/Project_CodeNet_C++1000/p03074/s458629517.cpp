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
    vector<int>nums;
    int cnt;
    if(s[0] != '1')nums.push_back(0);
    for(int i = 0;i<(int)s.size();i++) {
        cnt = 0;
        for(int j = i;j<(int)s.size();j++) {
            if(s[i] == s[j]) {
                i = j;
                cnt++;
            }
            else break;
        }
        nums.push_back(cnt);
        
    }
    
    vector<int>sum((int)nums.size()+1);
    rep(i,(int)nums.size()) {
        sum[i+1] = sum[i] + nums[i];
    }
    // rep(i,nums.size()) {
    //     cout << nums[i] << endl;
    // }
    // rep(i,sum.size()) {
    //     cout << sum[i] << endl;
    // }
    int ans = 0;
    for(int left = 0;left<(int)sum.size();left += 2) {
        int right = left+2*k+1;
        if(right>=(int)sum.size()) right = sum.size()-1;
        // cout << sum[right] << " " << sum[left] << endl;
        ans = max(ans,sum[right] - sum[left]);
    }
    cout << ans << endl;
}