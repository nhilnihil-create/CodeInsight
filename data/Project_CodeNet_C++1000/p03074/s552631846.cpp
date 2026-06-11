#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,k;
    string s;
    cin >> n >> k >> s;

    vector<int> nums;   //10101圧縮
    int now = 1;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]-'0'==now) cnt++;
        else{
            nums.push_back(cnt);
            cnt = 1;
            now ^= 1;
        }
    }
    nums.push_back(cnt);
    if(s.back()=='0') nums.push_back(0);
    //for(int i=0;i<nums.size();i++) cout << nums[i] << endl;

    int m = (int)nums.size();
    vector<int> sum(m+1,0); //累積和
    for(int i=0;i<m;i++) sum[i+1] = sum[i] + nums[i];

    int ans = 0;
    k = min(k,m/2);
    for(int i=0;2*k+1+i<=m;i+=2){
        ans = max(ans, sum[2*k+1+i]-sum[i]);
    }
    cout << ans << endl;

}