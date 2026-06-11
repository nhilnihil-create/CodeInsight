#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    int A, B, T;
    cin >> A >> B >> T;

    int sum = 0;
    for (double i = (double) A; i < (double) T + 0.5; i += (double) A) {
        sum += B;
    }

    cout << sum << endl;
    return 0;

}