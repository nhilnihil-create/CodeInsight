#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct csf {
    int c;
    int s;
    int f;
};

int main() {
    int n;
    cin >> n;
    vector<csf> a(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i].c >> a[i].s >> a[i].f;
    }

    for (int i = 0; i < n - 1; ++i) {
        int sum = 0;
        for (int j = i; j < n - 1; ++j) {
            if (sum < a[j].s) sum = a[j].s;
            else if (sum % a[j].f == 0);
            else sum = sum + a[j].f - sum % a[j].f;
            sum += a[j].c;
        }
        cout << sum << endl;
    }
    cout << 0 << endl;
}