#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    long long cnt = 0;
    int right = 0, sum = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && (sum ^ a[right]) == (sum + a[right])) sum += a[right++];
        cnt += right - left;
        sum -= a[left];
    }
    cout << cnt << endl;
    return 0;
}
