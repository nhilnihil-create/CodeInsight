#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0) {
            v.push_back(tmp);
        }
    }

    if (v.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    int count = 0;
    while (true) {
        int n = 0;
        while (v[0] % 2 == 0) {
            v[0] /= 2;
            n++;
        }
        v.erase(v.begin());
        if (v.size() == 0) {
            cout << count + n << endl;
            return 0;
        }
        int p = pow(3, n);
        for (int i = 0; i < v.size(); i++) {
            v[i] *= 3;
        }
        count += n;
    }
}