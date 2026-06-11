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

    int left=0;
    int right=0;
    int ans=0;
    int add = 2*k+1;
    int sum=0;

    for(int i=0;i<nums.size();i+=2){

        int nextleft = i;
        int nextright = min(i+add,(int)nums.size());

        while(left<nextleft){
            sum -= nums[left];
            left++;
        }
        while(right<nextright){
            sum += nums[right];
            right++;
        }

        ans = max(ans,sum);
    }

    cout << ans << endl;

}