#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

void PrintVec(VI& v) {
    for (Int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return;
}

int main(void) {
    VI num;
    VI v(100001);
    v[1] = 1;
    num.push_back(1);
    Int six = 6;
    while(six <= 100000) {
        v[six] = 1;
        num.push_back(six);
        six *= 6;
    }
    Int nine = 9;
    while(nine <= 100000) {
        v[nine] = 1;
        num.push_back(nine);
        nine *= 9;
    }
    sort(num.begin(), num.end());
    for (Int i = 2; i <= 100000; ++i) {
        v[i] = INT_MAX;
        bool exist = false;
        for (Int j = 0; j < num.size(); ++j) {
            if (i == num[j]) {
                exist = true;
            }
        }
        if (exist == true) {
            v[i] = 1;
        } else {
            for (Int j = 0; j < num.size(); ++j) {
                if (num[j] < i) {
                    v[i] = min(v[i], v[i - num[j]] + 1);
                }
            }
        }
    }
    Int n;
    cin >> n;
    cout << v[n] << endl;
    return 0;
}

