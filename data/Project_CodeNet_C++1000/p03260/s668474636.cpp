#include <iostream>
#include <vector>
#include <algorithm>

typedef int64_t ll;
using namespace std;

int main() {
    // freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    for (int i=1; i<=3; i++) {
        if ((a*b*i)%2 != 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}