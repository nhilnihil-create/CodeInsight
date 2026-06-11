#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];

    long long mi = 1LL << 60;
    int mii = -1;
    for (int i = 0; i < n; ++i) {
        if (mi > abs(sum - a[i] * n)) mi = abs(sum - a[i] * n), mii = i;
    }

    cout << mii << endl;
}