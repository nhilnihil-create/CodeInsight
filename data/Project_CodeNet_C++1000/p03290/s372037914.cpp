#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <numeric> // next_parmutation
#define ll long long
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
    int d, g;
    cin >> d >> g;

    vector<int> p(11), c(11);
    rep(i, d) cin >> p[i] >> c[i];

    int ans = 1e9;
    rep(bit, (1 << d)){
        //p[i]を全部解いてコンプリートボーナスを得る問題
        int sum = 0, max = -1, solved = 0;
        rep(i, d){
            if(bit >> i & 1){
                sum += 100*(i+1)*p[i]+c[i];
                solved += p[i];
            } else max = i;
        }
        //上で足りない場合
        if(sum < g){
            int s = 100 * (max + 1);
            int need = (g - sum + s - 1) / s;
            if(need >= p[max]){
                continue;
            }
            solved += need;
        }
        ans = min(ans, solved);
     }

    cout << ans << endl;
    }

