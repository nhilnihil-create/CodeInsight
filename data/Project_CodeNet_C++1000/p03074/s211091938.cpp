#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){

    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<int> nums;
    int now = 1;
    int cnt = 0;
    rep(i,n){
        if(s[i]==(char)('0'+now)) cnt++;
        else{
            nums.push_back(cnt);
            now ^= 1;
            cnt=1;
        }
    }
    if(cnt!=0) nums.push_back(cnt);

    //1-0-1-0-1-0-1のような配列
    if(nums.size() % 2 == 0) nums.push_back(0);

    int add = 2 * k + 1;
    vector<int> sum(nums.size()+1, 0);
    for(int i=0;i<nums.size();i++){
        sum[i+1] = sum[i] + nums[i];
    }

    int ans=0;
    for(int i=0;i<nums.size();i+=2){
        int left = i;
        int right = min(i+add, (int)nums.size());
        int tmp = sum[right] - sum[left];
        ans = max(tmp, ans);
    }
    cout<<ans<<endl;
    return 0;
}

