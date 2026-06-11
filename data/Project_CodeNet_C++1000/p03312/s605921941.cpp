#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>v;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }
    vector<long long>sum(n), mn(n + 2), mn2(n + 2);
    sum[0] = v[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i - 1] + v[i];
    }
    for(int i = 1; i < n - 2; i++){
        long long r = sum[i]/2 + (sum[i] % 2 != 0);
        int j = lower_bound(sum.begin(), sum.end(), r) - sum.begin();
        if(j == i){
            mn[i] = sum[i - 1];
        }
        else if(j == 0){
            mn[i] = sum[i] - sum[0];
        }
        else{
            mn[i] = max(sum[j - 1], sum[i] - sum[j]);
        }
        r = (sum[n - 1] - sum[i])/2 + ((sum[n - 1] - sum[i]) % 2 != 0);
        j = lower_bound(sum.begin(), sum.end(), r + sum[i]) - sum.begin();
        if(j == n - 1){
            mn2[i + 1] = sum[n - 2] - sum[i];
        }
        else if(j == i + 1){
            mn2[i + 1] = sum[n - 1] - sum[i + 1];
        }
        else{
            mn2[i + 1] = max(sum[j - 1] - sum[i], sum[n - 1] - sum[j]);
        }
    }
    long long ans = 1e18;
    for(int i = 1; i < n - 2; i++){
        long long a = min(mn[i], mn2[i + 1]);
        long long b = max(sum[i] - mn[i], sum[n - 1] - sum[i] - mn2[i + 1]);
        ans = min(ans, b - a);
    }
    cout << ans;
    return 0;
}