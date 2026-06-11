#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> D(n);
    copy_n(istream_iterator<int>(cin), n, D.begin());
    D.push_back(0);

    array<int, 13> cnt = {};
    for (const auto &d: D)
        cnt[d]++;

    for (const auto &c: cnt){
        if (c >= 3){
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 0;
    for (int bits = 0; bits < 1 << 13; bits++){
        int mi = 13;
        vector<int> A;
        for (int i = 0; i < 13; i++){
            if (cnt[i] == 0)
                continue;
            if (cnt[i] == 2){
                A.push_back(i);
                A.push_back(24 - i);
                continue;
            }
            if (bits >> i & 1){
                A.push_back(i);
            } else {
                A.push_back(24 - i);
            }
        }

        for (int i = 0; i < A.size(); i++){
            for (int j = i + 1; j < A.size(); j++){
                mi = min(mi, min((A[i] - A[j] + 24) % 24, (A[j] - A[i] + 24) % 24));
            }
        }
        ans = max(ans, mi);
    }

    cout << ans << endl;
}