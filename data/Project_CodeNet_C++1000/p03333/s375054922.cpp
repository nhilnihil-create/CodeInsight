#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int L[n], R[n]; for (int i = 0; i < n; i++) cin >> L[i] >> R[i];
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector<int> q = p;
    sort(p.begin(), p.end(), [&](int i, int j) { return R[i] < R[j]; });
    sort(q.begin(), q.end(), [&](int i, int j) { return L[i] > L[j]; });
    int pos = 0;
    long long sum1 = 0;
    auto itp = p.begin(), itq = q.begin();
    for (;;) {
        if (R[*itp] < pos) {
            sum1 += pos - R[*itp];
            pos = R[*itp];
            itp++;
        } else if (L[*itq] > pos) {
            sum1 += L[*itq] - pos;
            pos = L[*itq];
            itq++;
        } else break;
    }
    sum1 += abs(pos);
    long long sum2 = 0;
    itp = p.begin(), itq = q.begin();
    pos = 0;
    for (;;) {
        if (L[*itq] > pos) {
            sum2 += L[*itq] - pos;
            pos = L[*itq];
            itq++;
        } else if (R[*itp] < pos) {
            sum2 += pos - R[*itp];
            pos = R[*itp];
            itp++;
        } else break;
    }
    sum2 += abs(pos);
    cout << max(sum1, sum2) << endl;
}