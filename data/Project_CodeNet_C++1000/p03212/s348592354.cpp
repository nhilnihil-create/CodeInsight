#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N;
    cin >> N;
    deque<string> dq;
    dq.push_back("");
    ll ans = 0;
    while(!dq.empty()){
        string nums = dq.front();
        dq.pop_front();
        if(nums.size()<10){
            dq.push_back(nums+'3');
            dq.push_back(nums+'5');
            dq.push_back(nums+'7');
        }
        if(nums.find("3")==string::npos ||
           nums.find("5")==string::npos ||
           nums.find("7")==string::npos){
            continue;
        }else{
            ll num = stoll(nums);
            if(num<=N){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}