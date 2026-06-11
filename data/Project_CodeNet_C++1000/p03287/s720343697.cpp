#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    partial_sum(A.begin(), A.end(), A.begin());
    transform(A.begin(), A.end(), A.begin(), [M](int64_t x) {return x%M;});

    int64_t ans = count(A.begin(), A.end(), 0L);
    map<int,int> mp;
    for(auto e: A) {
        mp[e]++;
    }
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        int64_t val = itr->second;
        ans += val*(val-1) / 2;
    }

    cout << ans << endl;
    return 0;
}
