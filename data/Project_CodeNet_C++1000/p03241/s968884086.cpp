#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    if(M % N == 0) {
        cout << M / N << endl;
        return 0;
    }

    int ans = 1;
    for(int i = 2; i * i <= M; ++i) {
        if(M % i == 0) {
            if(M / i >= N) {
                ans = max(ans, i);
            }
            if(i >= N) {
                ans = max(ans, M / i);
            }
        }
    }
    cout << ans << endl;
}

