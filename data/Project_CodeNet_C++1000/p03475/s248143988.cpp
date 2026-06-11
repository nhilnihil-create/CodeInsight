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
    vector<uint64_t> C(N);
    vector<uint64_t> S(N);
    vector<uint64_t> F(N);
    rep(i, N-1) {
        cin >> C[i];
        cin >> S[i];
        cin >> F[i];
    }
    S[N-1] = 0;

    rep(i, N-1) {
        uint64_t arrive = 0;
        for(int j=i+1; j<N; ++j) {
            auto start = max(arrive, S[j-1]);
            start = ((start + F[j-1]-1) / F[j-1]) * F[j-1]; 
            arrive = start + C[j-1];
//            cout << "  N: " << j << "begin:" << start << " arrive " << arrive << endl;
        }
        cout << arrive << endl;
    }
    cout << 0 << endl;

    return 0;
}

