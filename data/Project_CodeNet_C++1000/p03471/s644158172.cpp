#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;
    vector<int> numMax(3, 0);

    numMax[0] = min(Y/10000, N);
    numMax[1] = min(Y/5000, N);
    numMax[2] = min(Y/1000, N);

    int x, y, z;
    bool find = false;
    for (int a=0; a<=numMax[0]; ++a) {
        for (int b=0; b<=numMax[1]; ++b) {
            int c = N - a - b;
            if (c < 0) continue;

            int v = a * 10000 + b * 5000 + c * 1000;
            if (v == Y) {
                find = true;
                x = a;
                y = b;
                z = c;
                break;
            }
        }
        if (find) break;
    }
    if (find)
        cout << x << ' ' << y << ' ' << z << endl;
    else
        cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}
