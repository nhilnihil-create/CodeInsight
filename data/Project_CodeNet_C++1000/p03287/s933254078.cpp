#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N; Int M; cin >> N >> M;

    vector<Int> A(100010), sum(100010, 0);
    map<Int, Int> rem_count; rem_count[0]++;
    rep1(i, N){
        cin >> A[i];
        sum[i] = sum[i-1] + A[i]; sum[i] %= M;
        rem_count[sum[i]]++;
    }

    Int ans = 0;
    for(pair<Int,Int> p : rem_count){
        ans += p.second * (p.second-1) / 2;
    }
    cout << ans << endl;
}