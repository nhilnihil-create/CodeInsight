#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    double A;
    cin >> N >> T >> A;

    int H;
    double div = 100000;
    int ans;

    for(int i=0; i<N; i++) {
        cin >> H;
        double avg_tmp = T - H * 0.006;
        if(abs(avg_tmp-A) < div) {
            ans = i+1;
            div = abs(avg_tmp-A);
        }
    }
    cout << ans << endl;
}