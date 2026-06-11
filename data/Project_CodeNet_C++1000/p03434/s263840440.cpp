#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long int lli;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    vector<int> a;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < N; i++) {
        if ((i % 2) == 0) {
            sum += a[i];
        } else {
            sum -= a[i];
        }
    }
    cout << sum << endl;
    return 0;
}
