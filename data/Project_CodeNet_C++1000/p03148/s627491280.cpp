#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<long long, int> >v, v2;
    vector<long long>mx(n + 3, -1);
    for(int i = 0; i < n; i++){
        long long x;
        int t;
        cin >> t >> x;
        v.push_back(make_pair(x, t));
        mx[t] = max(mx[t], x);
    }
    for(int i = 1; i <= n; i++){
        if(mx[i] != -1){
            v2.push_back(make_pair(mx[i], i));
        }
    }
    sort(v.rbegin(), v.rend());
    sort(v2.rbegin(), v2.rend());
    int p = v2.size();
    vector<long long>sum(p), idx(p), sum2(n);
    sum2[0] = v[0].first;
    for(int i = 1; i < n; i++){
        sum2[i] = sum2[i - 1] + v[i].first;
    }
    sum[0] = v2[0].first;
    idx[0] = lower_bound(v.begin(), v.end(), v2[0], greater<pair<long long, int> >()) - v.begin();
    for(int i = 1; i < p; i++){
        sum[i] = sum[i - 1] + v2[i].first;
        idx[i] = lower_bound(v.begin(), v.end(), v2[i], greater<pair<long long, int> >()) - v.begin();
    }
    long long ans = 0;
    for(int i = 0; i < min(k, p); i++){
        long long cur = sum[i];
        int lo = 0, hi = n - 1;
        while(hi - lo >= 2){
            int mid = (hi + lo)/2;
            int p = upper_bound(idx.begin(), idx.end(), mid) - idx.begin();
            p = min(p, i + 1);
            if(mid + 1 - p >= k - i - 1){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        for(int mid = lo; mid <= hi; mid++){
            int p = upper_bound(idx.begin(), idx.end(), mid) - idx.begin();
            p = min(p, i + 1);
            if(mid + 1 - p >= k - i - 1){
                cur = cur - sum[p - 1] + sum2[mid] + 1LL * (i + 1) * (i + 1);
                break;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}