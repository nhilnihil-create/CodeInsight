#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N; cin >> N;

    vector<Int> A(N);
    rep(i,N) cin >> A[i];

    vector<Int> S = {A[0]};
    rep1(i,N-1) S.push_back(S[i-1]+A[i]);

    Int ans = 1e18;
    for(int i=2; i<N-1; i++){
        // 左側 [0, i) 
        Int left_sum = S[i-1];
        int mid_l = lower_bound(S.begin(), S.begin()+i, left_sum/2) - S.begin();

        pair<Int,Int> left = {S[mid_l], left_sum-S[mid_l]};
        if(mid_l != 0){
            pair<Int,Int> left2 = {S[mid_l-1], left_sum-S[mid_l-1]};
            if (abs(left2.first-left2.second) < abs(left.first-left.second)){
                left = left2;
            }
        }

        // 右側 [i,N)
        int mid_r = lower_bound(S.begin()+i, S.end(), (S.back() + left_sum)/2) - S.begin();
        pair<Int,Int> right = {S[mid_r] - left_sum, S.back()-S[mid_r]};
        if(mid_r != i){
            pair<Int,Int> right2 = {S[mid_r-1] - left_sum, S.back()-S[mid_r-1]};
            if (abs(right2.first-right2.second) < abs(right.first-right.second)){
                right = right2;
            }
        }

        Int M = max(left.first, max(left.second, max(right.first, right.second))); 
        Int m = min(left.first, min(left.second, min(right.first, right.second)));
        ans = min(ans, M-m);
    }

    cout << ans << endl;
}