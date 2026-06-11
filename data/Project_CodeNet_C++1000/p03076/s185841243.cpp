#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    vector<ll> v(5);
    for (int i = 0; i < 5; ++i) cin >> v[i];
    vector<ll> array = {0, 1, 2, 3, 4};
    ll min_time = 10000;
    do {
        ll tmp_min_time = 0;
        for (int i = 0; i < 4; ++i) {
            tmp_min_time += v[array[i]];
            while(tmp_min_time%10 != 0) tmp_min_time++;
        }
        tmp_min_time += v[array[4]];
        min_time = min(min_time, tmp_min_time);
    }
    while (next_permutation(array.begin(), array.end()));
    cout << min_time << endl;
}