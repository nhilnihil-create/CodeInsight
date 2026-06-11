#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    vector<int> in = X;
    sort(X.begin(), X.end());

    int middle = N / 2;
    for (int i = 0; i < N; i++) {
        if (in[i] >= X[middle]) {
            cout << X[middle - 1] << endl;
        } else {
            cout << X[middle] << endl;
        }
    }

    return 0;
}
