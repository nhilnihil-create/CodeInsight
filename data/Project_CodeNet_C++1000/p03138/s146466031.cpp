#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int digk = log2(k + 0.1) + 1;
    if(k == 0) digk = 0;
    vector<int> bit_w(digk, 0);
    // これだと x が k を超えちゃう
    for(int i=0; i<digk; i++){
        int bcnt = 0;
        int bit = (1LL<<i);
        for(int j=0; j<n; j++){
            if((a[j] & bit) == 0){
                bcnt++;
            }
        }
        if(bcnt > n-bcnt){
            bit_w[i] = bit * (2*bcnt-n);
        }
    }

    // 半分全探索からの二分探索
    vector<int> sum1((1LL<<digk/2), 0);
    vector<int> sum2((1LL<<(digk-digk/2)), 0);
    vector<pair<int, int>> elim_sum1;
    vector<pair<int, int>> elim_sum2;
    int now_v = -1;
    for(int i=0; i<(1<<digk/2); i++){
        for(int j=0; j<digk/2; j++){
            if(i & (1LL<<j)){
                sum1[i] += bit_w[j];
            }
        }
        if(now_v < sum1[i]){
            now_v = sum1[i];
            elim_sum1.push_back(make_pair(i, sum1[i]));
        }
    }
    now_v = -1;
    for(int i=0; i<(1<<(digk-digk/2)); i++){
        for(int j=0; j<digk-digk/2; j++){
            if(i & (1LL<<j)){
                sum2[i] += bit_w[j+digk/2];
            }
        }
        // 荷物が重くなってるのに価値が上がってないような候補はあほなので除いておきたい
        if(now_v < sum2[i]){
            now_v = sum2[i];
            elim_sum2.push_back(make_pair((i<<digk/2), sum2[i]));
        }
    }

    int maxv = 0, maxw = 0;
    for(int i=0; i<elim_sum1.size(); i++){
        int ok_weight = k - elim_sum1[i].first;
        pair<int, int> p = make_pair(ok_weight+1, 0);
        auto itr = lower_bound(elim_sum2.begin(), elim_sum2.end(), p);
        int idx = distance(elim_sum2.begin(), itr);
        if(idx > 0){
            idx--;
            int val = elim_sum1[i].second + elim_sum2[idx].second;
            if(maxv < val){
                maxv = val;
                maxw = elim_sum1[i].first + elim_sum2[idx].first;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += maxw ^ a[i];
    }
    cout << ans << endl;

    return 0;
}