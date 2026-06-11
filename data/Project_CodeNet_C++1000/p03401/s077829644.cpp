#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


int main()
{
    vector<long long> a(10e5);
    long long N;
    cin >> N;
    a[0] = 0;
    a[N + 1] = 0;
    for (auto i = 1; i <= N; i++) {
        cin >> a[i];
    }

    long long cost = 0;
    for (auto i = 1; i <= N + 1; i++) {
        cost += abs(a[i] - a[i - 1]);
    }

    for (auto i = 1; i <= N; i++) {
        long long diff = 0;
        if ((a[i] - a[i - 1]) * (a[i + 1] - a[i]) < 0) {
            // cout << "remove: " << a[i] << endl;
            diff = min(abs(a[i] - a[i - 1]), abs(a[i + 1] - a[i])) * 2;
        }
        cout << cost - diff << endl;
    }
}
