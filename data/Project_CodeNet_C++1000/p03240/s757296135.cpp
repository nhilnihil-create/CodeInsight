#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x,y,h,H,idx_H;
int main() {
    int N; cin >> N;
    vector<tuple<ll, ll, ll>> A(N);
    for (int i=0; i<N; ++i) {
        cin >> x >> y >> h;
        if (h > 0) idx_H = i;
        A[i] = make_tuple(x,y,h);
    }
    for (int cx = 0; cx<=100; cx++){
        for (int cy=0; cy<=100; cy++){
            H = get<2>(A[idx_H]) + abs(get<0>(A[idx_H])-cx) + abs(get<1>(A[idx_H])-cy);
            bool can = true;
            for (auto a : A) {
                tie(x,y,h) = a;
                if (h != max((H - abs(x-cx) - abs(y-cy)), (ll)0)) can = false;
                // if (h > 0 && h != H - abs(x-cx) - abs(y-cy)) can = false;
                // if (h== 0 && (H - abs(x-cx) - abs(y-cy)) > 0) can = false;
            }
            if (can) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }

}