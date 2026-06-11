#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int main(){
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h.at(i);

    int ans = 0;
    while (true) {
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (h.at(i) > 0) {
                h.at(i)--;
                flag = true;
            } else {
                if (flag) ans++;
                flag = false;
                cnt++;
            }
        }
        if (cnt >= N) break;
        else {
            if (flag) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
