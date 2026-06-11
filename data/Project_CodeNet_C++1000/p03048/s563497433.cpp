#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int main() {
    int R, G, B, N;
    int ans = 0;
    cin >> R >> G >> B >> N;

    for (int r = 0; r <= N; r++) {
        for (int g = 0; g <= N; g++) {
            double b;
            b = (double)(N-r*R-g*G)/(double)B;
            if (b >= 0 && floor(b) == b) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
