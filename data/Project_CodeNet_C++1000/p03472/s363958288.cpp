#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> b(n);
    int maxA = -1;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a >> b[i];
        maxA = max(a, maxA);
    }
    sort(b.begin(), b.end(), greater<int>());

    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] < maxA)break;
        sum += b[i];
        count++;
        if (sum >= h) {
            cout << count << endl;
            return 0;
        }
    }
    int nokori = h - sum;

    if (nokori % maxA != 0)count++;
    count += nokori / maxA;
    cout << count << endl;
}