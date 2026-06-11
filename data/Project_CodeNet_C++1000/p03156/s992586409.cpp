#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9+7;
signed main() {
    int N,A,B;
    cin >> N >> A >> B;
    vector<int>P(N);
    int cnt = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        if(P[i] > A && P[i] <= B) {
            cnt++;
        }
        else if(P[i] <= A) {
            cnt2++;
        }
        else {
            cnt3++;
        }
    }
    cout << min(min(cnt,cnt2),cnt3) << endl;
}