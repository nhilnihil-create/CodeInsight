#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    long min = pow(10, 9);
    long max = 1;
    for (int i = 0; i < N; ++i) {
        long tmp;
        cin >> tmp;
        min = std::min(min, tmp);
        max = std::max(max, tmp);
    }
    cout << max - min << endl;
}