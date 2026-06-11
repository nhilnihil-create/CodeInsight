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
    int N, H;
    cin >> N >> H;

    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (b[i] <= a[0]) break;
        H -= b[i];
        count++;
        if (H <= 0) {
            cout << count << endl;
            return 0;
        }
    }

    while (H > 0) {
        count++;
        H -= a[0];
    }
    cout << count << endl;

    return 0;
}
