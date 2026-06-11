#include <iostream>
using namespace std;

int main(void) {
    int a, b, c, x, ret = 0;
    cin >>a >>b >>c >>x;
    for (int ai = 0; ai <= a; ai++) {
        for (int bi = 0; bi <= b; bi++) {
            for (int ci = 0; ci <= c; ci++) {
                if (500 * ai + 100 * bi + 50 * ci == x) ++ret;
            }
        }
    }
    cout << ret << endl;
    return 0;
}