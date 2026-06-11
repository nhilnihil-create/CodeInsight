#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF 1E18



int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<int> nums;

    int now = 1;
    int cnt = 0;
    rep(i,n){
        if(s[i] == (char)('0' + now)) ++cnt;
        else{
            nums.push_back(cnt);
            now = 1 - now;
            cnt = 1;
        }
    }
    if(cnt != 0) nums.push_back(cnt);

    if(nums.size() % 2 == 0) nums.push_back(0);


    int add = 2*k + 1;
    int ans = -1;
    for(int i=0; i<nums.size(); i+=2){
        int left = i;
        int right = min(i+add, (int)nums.size());
        int temp = 0;
        for(int j=left; j<right; j++){
            temp += nums[j];
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}
