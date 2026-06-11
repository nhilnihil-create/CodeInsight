#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {   
    // 4 / n = 1 / a + 1/ b + 1/ c;
    // 4abc = nab + nbc + nac
    // a = nbc / (4bc - nb - nc)
    long long int n;
    cin >> n;
    for (long long int c = 1; c <= 3500; c++) {
        for (long long int b = 1; b <= 3500; b++) {
            if (4 * b * c - n * b - n * c <= 0) {
                continue;
            }
            if (n * b * c % (4 * b * c - n * b - n * c) == 0) {
                cout << n * b * c / (4 * b * c - n * b - n * c) << " " << b << " " << c << endl;
                return 0; 
            }
        }
    }
}


