#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long N;
    cin >> N;
 
    for (long h=1; h<=3500; h++) {
        for (long n=1; n<=3500; n++) {
            long double tmp = 4 * h * n - N * n - N * h;
            if (tmp <= 0) continue;
            long double w = N * h * n / tmp;
            if (ceil(w) == floor(w)) {
                cout << h << " " << n << " " << (long)w << endl;
                return 0;
            }
        }
    }
}
