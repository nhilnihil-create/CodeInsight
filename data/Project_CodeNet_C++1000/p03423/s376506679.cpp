#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    
    cin >> N;

    if ((N % 3 == 0) && (N >= 3)) {
        cout << N / 3 << endl;
        return 0;
    } else if ((N % 3 == 1) || (N % 3 == 2) && (N >= 3)) {
        cout << N / 3 << endl;
        return 0;
    }
    cout << 0<< endl;
    return 0;
}