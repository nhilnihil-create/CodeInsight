#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int n;
    cin >> n;

    vector<map<int, int>> v(2);
    for (auto i = 0; i < n; i++) {
        int a; cin >> a;
        if (i % 2 == 0) v[0][a]++;
        else v[1][a]++;
    }

    vector<int> max_count(4, 0), max_index(4, 0);
    int ans, index = 0;
    for (auto & vec : v) {
        for (auto i = 0; i < 2; i++) {
            for (auto & elm : vec) {
                if (max_count[index] < elm.second) {
                    max_count[index] = elm.second;
                    max_index[index] = elm.first;
                }
            }
            vec.erase(max_index[index]);
//            cout << max_count[index] << " " << max_index[index] << endl;
            index++;
        }
    }

    if(max_index[0] == max_index[2]) {
        if(max_count[0] + max_count[3] < max_count[1] + max_count[2]) {
            ans = n - (max_count[2] + max_count[1]);
        } else {
            ans = n - (max_count[3] + max_count[0]);
        }
    } else {
        ans = n - (max_count[0] + max_count[2]);
    }

    cout << ans << endl;
    return 0;
}