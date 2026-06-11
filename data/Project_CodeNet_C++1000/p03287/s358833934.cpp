#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
//--------------------
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//------------

//-------
void func() {
    int N,M;
    cin >> N >> M ;
    int arr[N];
    for (int j = 0; j < N; ++j) {
        cin >> arr[j];
    }
    long long ans = 0;
    vector<long long> prefixSum(N + 1);
    prefixSum.at(0) = 0;
    for (int k = 0; k < N ; ++k) {
        prefixSum.at(k + 1) = (prefixSum.at(k) + arr[k]) % M;
    }
    map<int ,int> counter;

    for (int i = 0; i <= N; ++i) {
        if(counter.count(prefixSum.at(i))) {
            ans += counter[prefixSum.at(i)];
            counter[prefixSum.at(i)]++;
        } else {
            counter[prefixSum.at(i)] = 1;
        }
    }
    cout << ans << endl;
}

int main() {
    func();
    return 0;
}