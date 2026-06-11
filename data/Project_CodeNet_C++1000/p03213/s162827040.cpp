#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int N;
    cin >> N;

    bool Prime[101];
    rep(i, 101) Prime[i] = true;
    Prime[0] = Prime[1] = false;
    for (int i=2; i<=100; i++) {
        if (Prime[i]) {
            for (int j=i*2; j<=100; j+=i) Prime[j] = false;
        }
    }

    int CntP[101] = {};
    for (int n=1; n<=N; n++) {
        for (int i=2; i<=N; i++) {
            if ((Prime[i]) && (n%i==0)) {
                int tmp = n;
                while ((tmp > 1) && (tmp%i==0)) {
                    CntP[i]++;
                    tmp /= i;
                }
            }
        }
    }

    int over3=0, over5=0, over15=0, over25=0, over75=0;
    rep(i, N+1) {
        if (CntP[i] >= 2) over3++;
        if (CntP[i] >= 4) over5++;
        if (CntP[i] >= 14) over15++;
        if (CntP[i] >= 24) over25++;
        if (CntP[i] >= 74) over75++;
        // cout << i << " : " << CntP[i] << endl;
    }

    int ans = 0;
    ans += (over5 * (over5 - 1)) / 2 * (over3 - 2); 
    ans += over15 * (over5 - 1); 
    ans += over25 * (over3 - 1); 
    ans += over75;

    cout << ans << endl;

    return 0;
}

 