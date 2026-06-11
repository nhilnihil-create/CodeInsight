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
void func() {
    int N,M;
    cin >> N >> M ;
    int sum = 0;
    long long ans = 0;
    map<int ,int> counter;
    counter[0] = 1;
    for (int i = 0; i < N; ++i) {
        int a ;
        cin >> a;
        sum += a;
        sum %= M;
        if(counter[sum]) {
            ans += counter[sum];
            counter[sum] += 1;
        } else {
            counter[sum] = 1;
        }
    }
    cout << ans << endl;
}

int main() {
    func();
    return 0;
}
