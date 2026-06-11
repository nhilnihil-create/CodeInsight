#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
typedef long long ll;
typedef pair<ll, ll> P;

string S;

int main(){
    cin >> S;

    bool ok = false;
    for(int i=0;i<S.size()-1;i++){
        if(S[i] != S[i+1])  ok = true;
    }
    if(!ok){
        cout << S.size() << endl;
        return 0;
    }

    vector<int> nums;
    int cnt = 1;
    for(int i=1;i<S.size();i++){
        if(S[i-1] != S[i]){
            nums.push_back(cnt);
            cnt = 0;
        }
        cnt++;
    }
    nums.push_back(cnt);

    int l = 0, r = nums.size() - 1;
    ll ans = INF;
    while(l != r){
        if(nums[l] < nums[r]){
            nums[l+1] += nums[l];
            ans = min(ans, (ll)S.size() - nums[l]);
            l++;
        } else {
            nums[r-1] += nums[r];
            ans = min(ans, (ll)S.size() - nums[r]);
            r--;
        }
    }
    
    cout << ans << endl;
}