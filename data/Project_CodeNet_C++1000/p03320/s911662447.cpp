#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int K;

int main() {
    cin >> K;
    long long snuke = 1;
    for (int i = 0; i < K; i++) {
        long long sum = 0, d = 1;;
        while (snuke / d > 0) {
            sum += snuke / d % 10;
            d *= 10;
        }
        d = 1;
        while (snuke > sum * d) {
            int x = snuke / d % 10;
            sum += 9 - x;
            snuke += (9 - x) * d;
            d *= 10;
        }
        cout << snuke << endl;
        snuke++;
    }
}


