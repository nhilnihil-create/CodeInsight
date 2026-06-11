#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, P;

int main() {
    cin >> N >> P;
    if (N == 1) {
        cout << P << endl;
        return 0;
    }

    long long d = 2, ans = 1;
    bool over = false;
    
    int cnt = 0;
    while(P % d == 0) {
        P /= d;
        cnt++;
    }
    for (int i = 0; i < cnt / N; i++) {
        ans *= d;
    }
    d++;
    
    while(!over) {
        int cnt = 0;
        while(P % d == 0) {
            P /= d;
            cnt++;
        }
        for (int i = 0; i < cnt / N; i++) {
            ans *= d;
        }
        d += 2;

        if (d * d > P ) {
            over = true;
        }
    }
    cout << ans << endl;
}
