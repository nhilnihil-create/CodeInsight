#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    for (long long i = N; i > 0; i--) {
        if (static_cast<long long>(sqrt(i)) * static_cast<long long>(sqrt(i)) == i) {
            cout << i << endl;
            break;
        }
    }
}
