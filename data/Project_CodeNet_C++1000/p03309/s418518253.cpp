#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int n;
    int middle;
    long long ans = 1000000000000000;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        a.at(i) -= i + 1;
    }
    sort(a.begin(), a.end());
    long long sum = 0;
    if (n % 2 == 0) {
        for (int i = a.at(n / 2); i <= a.at(n / 2 + 1); i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                sum += abs(a.at(j) - i);
            }
            ans = min(ans, sum);
        }
    }
    else {
        middle = a.at(n / 2);
        for (int i = 0; i < n; i++) {
            sum += abs(a.at(i) - middle);
        }
        ans = sum;
    }
    cout << ans << endl;
}