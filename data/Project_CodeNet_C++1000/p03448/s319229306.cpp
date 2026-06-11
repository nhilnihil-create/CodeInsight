#include <iostream>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int pattern = 0;
    for (int a=0; a<=A; ++a) {
        int resA = X - 500 * a;
        for (int b=0; b<=B; ++b) {
            int resB = resA - 100 * b;
            if ((resB % 50) == 0) {
                int c = resB / 50;
                if ((c >= 0) && (c <= C)) ++pattern;
            }
        }
    }
    cout << pattern << endl;
}
