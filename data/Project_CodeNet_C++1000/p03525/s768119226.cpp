#include <bits/stdc++.h>
using namespace std;
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

int func (vector<int> A) {
    int mn = 100;
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = i+1; j < (int)A.size(); j++) {
            int dis = abs(A[i]-A[j]);
            chmin(mn, dis);
        }
    }
    return mn;
}

int main() {
    int N;
    cin >> N;
    vector<int> D(N+1, 0);
    for (int i = 0; i < N; i++) cin >> D[i];
    // 25人以上 (N >= 24) の場合、鳩ノ巣原理より答えは 0
    // ここまでは合ってるっぽい
    if (N >= 24) { cout << 0 << endl; return 0; }
    
    /*
        2^23 = 8388608 = 8.3 * 1e6
        2^23 * 23 = 1.9 * 1e8
    */
    sort(D.begin(), D.end());
    vector<int> t1, t2;
    for (int i = 0; i <= N; i++) {
        if (i&1) t1.emplace_back(D[i]);
        else t1.emplace_back((24-D[i])%24);
    }
    for (int i = 0; i <= N; i++) {
        if (i&1) t2.emplace_back((24-D[i])%24);
        t2.emplace_back(D[i]);
    }
    
    int ans = max(func(t1), func(t2));
    cout << ans << endl;
    return 0;
}
    