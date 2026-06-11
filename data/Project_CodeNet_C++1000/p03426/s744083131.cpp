#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

typedef long long ll;
int H, W, D, Q;

vector<tuple<int, int, int>> A;
vector<ll> cum_mp;

bool compare(tuple<int, int, int> &lhs, tuple<int, int, int> &rhs) {
    return get<0>(lhs) < get<0>(rhs);
}

int main() {
    cin >> H >> W >> D;

    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            int tmp;
            cin >> tmp;
            A.push_back(make_tuple(tmp, h, w));
        }
    }

    sort(A.begin(), A.end(), compare);

    for(int i = 0; i < D; i++) {
        cum_mp.push_back(0);
    }

    for(int i = D; i < H*W; i++) {
        cum_mp.push_back(cum_mp[i-D] + (ll)(abs(get<1>(A[i]) - get<1>(A[i-D])) + abs(get<2>(A[i]) - get<2>(A[i-D]))));
    }
    
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << cum_mp[R-1] - cum_mp[L-1] << endl;
    }



    return 0;
}