#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

// 分数を小数に変換する関数
double Fraction(Int numerator, Int denominator) {
    return (double)((double)(numerator) / (double)(denominator));
}

int main(void) {
    Int n, k;
    cin >> n >> k;
    Int timesMax = ceil(log2(k));
    Int array[timesMax + 1];
    for (Int i = 0; i <= timesMax; ++i) {
        array[i] = 0;
    }
    for (Int i = 1; i <= n; ++i) {
        Int tempK = 0;
        Int tempI = i;
        while (1) {
            if (tempI >= k) {
                array[tempK]++;
                //cout << i << " " << tempK << endl;
                break;
            } else {
                tempI *= 2;
                tempK++;
            }
        }
    }
    Int sum = 0;
    for (Int i = 0; i <= timesMax; ++i) {
        // cout << i << " " << array[i] << endl;
        array[i] *= pow(2, timesMax - i);
        sum += array[i];
    }
    cout << fixed << setprecision(10) << Fraction(sum, n * pow(2, timesMax)) << endl;
    return 0;
}
