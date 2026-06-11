#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t s;
    cin >> s;
    vector<bool> a(1000000, false);
    long long m = 1;
    a[s] = true;
    long long current = s;
    while (true) {
        current = (current % 2 == 0) ? (current / 2) : (3 * current + 1);
        if (a[current]) {
            break;
        }
        else {
            a[current] = true;
            ++m;
        }
    }
    cout << m + 1 << endl;
    return EXIT_SUCCESS;
}