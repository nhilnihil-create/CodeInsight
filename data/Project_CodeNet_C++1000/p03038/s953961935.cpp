#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;

// select top N number from A and Ci x Bi gathered
int main() {
    int N, M, ai, bi, ci;
    cin >> N >> M;
    // cout << endl << "----" << endl;
    vector<int> A;
    vector<pair<int, int>> BC;
    rep(i, N) {
        cin >> ai;
        A.push_back(- ai);
    }
    make_heap(A.begin(), A.end());

    rep(i, M){
        cin >> bi >> ci;
        BC.push_back(make_pair(ci, bi));
    }
    sort(BC.begin(), BC.end(), greater<pair<int,int>>());



    rep(i, M){
        bi = BC[i].second;
        ci = BC[i].first;
        rep (j, bi){
            if (- ci < A.front()) {
                // cout << "ci: " << ci << " front of A is : " << A.front();
                pop_heap(A.begin(), A.end());
    // for (auto& each : A) cout << each << " "; cout << endl;
                A.pop_back();
    // for (auto& each : A) cout << each << " "; cout << endl;

                A.push_back(- ci);
                push_heap(A.begin(), A.end());
            } else {
                break;
            }
        }
    }
    // for (auto& each : A) cout << each << " " << endl;
    ll sum = - accumulate(A.begin(), A.end(), 0LL);
    cout << sum << endl;
}
    // sort(A.begin(), A.end(), greater<int>());

    // int cur_cnt = 0, cur_sum = 0;
    // rep(i, M) {
    //     // check cnt border
    //     if (cur_cnt + change_cnt >= N) {
    //         change_cnt = N - cur_cnt;
    //     }
    //     cur_cnt += change_cnt;
    //     rep(j, change_cnt) {
    //         if (A[])
    //     }



    //     // end
    //     if (cur_cnt == N) {
    //         break;
    //     }
    // }