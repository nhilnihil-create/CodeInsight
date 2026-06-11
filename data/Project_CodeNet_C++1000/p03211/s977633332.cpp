#include <iostream>
using namespace std;
int main() {
    long long s;
    cin >> s;
    int minDiff = 999;
    for (long long i=1; s/i>=100; i*=10) {
        int threeNumbers = s/i - (s/(i*1000))*1000;
        minDiff = min(minDiff, abs(753-threeNumbers));
    }
    cout << minDiff << endl;
}