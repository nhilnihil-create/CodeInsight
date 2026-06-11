#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, K;
    cin >> N >> K;
    vector<long long> a(N+1, 0);
    FOR(i, 1, N+1) cin >> a[i];

    // 累積和
    FOR(i, 1, N+1) a[i] += a[i-1];
    
    vector<long long> all_comb;
    FOR(l, 1, N+1){
        FOR(r, l, N+1){
            all_comb.push_back(a[r]-a[l-1]);
        }
    }

    long long ans = 0;
    // 上の桁から決めていく
    for(int i = 40; i >= 0; --i){
        vector<long long> tmp;
        for(auto v: all_comb){
            if(v & ((long long)1 << i)) tmp.push_back(v);
        }
        if(tmp.size() >= K){
            ans += ((long long)1 << i);
            all_comb = tmp;
            //cout << i << " " << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}