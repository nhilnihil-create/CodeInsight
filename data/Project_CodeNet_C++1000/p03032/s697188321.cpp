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
bool DEBUG = false;

int main() {
    // input
    int N, K;
    cin >> N >> K;
    vector<ll> V(N);
    rep(i, N) cin >> V[i];

    // input check
    int num_minus = 0;
    ll sum_plus = 0;
    rep(i, N) {
        if (V[i] < 0) num_minus++;
        else sum_plus += V[i];
    }
    // if K is large enough to check all
    if (K >= N + num_minus) {
        if (DEBUG) cout << "enough K. finishing...  ";
        cout << sum_plus << endl;
        return 0;
    }

    // 
    ll ans = 0;
    int num_plus = N - num_minus;
    rep(max_dump, min(K/2, num_minus) + 1){
        if (DEBUG) cout << "max_dump: " << max_dump << endl;
        int max_num_take = K - max_dump;
        rep(max_num_take_from_right, max_num_take + 1){
            // take from V
            int max_num_take_from_left = max_num_take - max_num_take_from_right;
            vector<ll> taken;
            // take from left
            bool start = false;
            for (int left=max_num_take_from_left - 1; left >=0; left--){
                if (V[left] > 0) start = true;
                if (V[left] <= 0 && !start) continue;
                taken.push_back(- V[left]);
                push_heap(taken.begin(), taken.end());
            }
            // do same for right
            start = false;
            for (int right=N-max_num_take_from_right; right < N; right++){
                if (V[right] > 0) start = true;
                if (V[right] <= 0 && !start) continue;
                taken.push_back(- V[right]);
                push_heap(taken.begin(), taken.end());
            }

            // dump as long as front is originally negative
            rep(dump, max_dump) {
                if (!taken.empty() && taken.front() > 0) {
                    pop_heap(taken.begin(), taken.end());
                    taken.pop_back();
                }
                else break;
            }

            // sum all ans take max
            ans = max(ans, - accumulate(taken.begin(), taken.end(), 0LL));
        }
    }
    cout << ans << endl;
}

// dump: 0~K/2  operation: 0~(K-dump)  combination: operation
// time: (dump * log(operation)) * combination * dump => 50 * log(100) * 100 * 50