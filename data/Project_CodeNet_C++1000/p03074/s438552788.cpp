#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> nums;
    int now=1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]==(char)('0'+now)){
            cnt++;
        }else{
            nums.push_back(cnt);
            now = 1-now;
            cnt = 1;
        }
    }
    if(cnt!=0) nums.push_back(cnt);
    if(nums.size()%2==0) nums.push_back(0);

    int cum[nums.size()+1];
    cum[0] = 0;
    for(int i=0;i<nums.size();i++){
        cum[i+1] = cum[i] + nums[i];
    }

    int ans = 0;
    int add = 2*k+1;
    for(int i=0;i<nums.size();i+=2){
        int left = i;
        int right = min(i+add,(int)nums.size());
        int sum = cum[right]-cum[left];
        ans = max(ans,sum);
    }

    cout << ans << endl;


}