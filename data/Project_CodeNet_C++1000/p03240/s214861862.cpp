#include <iostream>
using namespace std;
using LL = long long;

int N;
LL X[101] = {};
LL Y[101] = {};
LL H[101] = {};

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        scanf("%lld%lld%lld", X + i, Y + i, H + i);
    }
    for(int y = 0; y <= 100; ++y) {
        for(int x = 0; x <= 100; ++x) {
            int g = -1;
            for(int i = 0; i < N; ++i) {
                if(H[i] > 0) {
                    g = H[i] + abs(X[i] - x) + abs(Y[i] - y);
                    break;
                }
            }

            bool found = true;
            for(int i = 0; i < N; ++i) {
                if(H[i] != max(g - abs(X[i] - x) - abs(Y[i] - y), 0LL)) {
                    found = false;
                    break;
                }
            }
            if(!found) continue;
            else {
                cout << x << " " << y << " " << g << endl;
                return 0;
            }
        }
    }
}
