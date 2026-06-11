//過去問演習はここ
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long K, A, B; cin >> K >> A >> B;
    if (B - A <= 2) {
        cout << K + 1 << endl;
    }
    else {
        long long operate = max((long long)0, (K - (A - 1)) / 2);
        cout << K + 1 - operate * 2 + B * operate - A * operate << endl;
    }
}