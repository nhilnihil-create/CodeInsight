#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int ub = 1 << 30, lb = 0;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        vector<int> s(n+1);
        s[0] = n+1;
        for (int i = 1; i <= n; i++) s[i] = s[i-1] + (a[i-1] <= mid ? 1 : -1);
        long long sum = 0;
        vector<int> bit(2*n+2);
        for (int i = 0; i <= n; i++) {
            for (int j = s[i]-1; j > 0; j -= j&-j) sum += bit[j];
            for (int j = s[i]; j < bit.size(); j += j&-j) bit[j]++;
        }
        if ((long long)n * (1+n) / 4 < sum) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
}
