#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    vector<int64_t> S(N);
    rep(i, N) {
        cin >> A[i];
        S[i] = A[i];
    }
    map<int64_t, int64_t> freq;
    freq[0]++;
    for(int i=1; i<N; ++i) {
        S[i] += S[i-1];
    }
    for(int i=0; i<N; ++i) {
        freq[S[i]]++;
    }

    uint64_t ret = 0;
    for(auto itr: freq) {
        if(itr.second < 1) 
            continue;
        int64_t add = (itr.second * (itr.second - 1)) / 2;
        ret += add;
    }
    cout << ret << endl;

    return 0;
}

