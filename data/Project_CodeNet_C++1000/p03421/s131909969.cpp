#include <bits/stdc++.h>

using namespace std;

using i64 = long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


signed main(){
    i64 n, a, b;
    cin >> n >> a >> b;
    if(a + b - 1 > n || a * b < n){
        cout << -1 << endl;
        return 0;
    }
    vector<i64> v;
    for(int i = 0; i < a; ++i)
        v.emplace_back(i);
    for(int i = 1; i < b; ++i)
        v.emplace_back(-1L * i * a);
    if(v.size() == n){
        auto w = v;
        sort(w.begin(), w.end());
        for(int k = 0; k < n; ++k){
            cout << distance(w.begin(), lower_bound(w.begin(), w.end(), v[k])) + 1 << " \n"[k == n - 1];
        }
        return 0;
    }
    for(int i = 1; i < b; ++i){
        for(int j = 1; j < a; ++j){
            v.emplace_back(-1L * i * a + j);
            if(v.size() == n){
                auto w = v;
                sort(w.begin(), w.end());
                for(int k = 0; k < n; ++k){
                    cout << distance(w.begin(), lower_bound(w.begin(), w.end(), v[k])) + 1 << " \n"[k == n - 1];
                }
                return 0;
            }
        }
    }
}
