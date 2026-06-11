#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    int ans, N, tmp, odd = 1;
    vector<int> A;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
        if (tmp % 2 == 0) {
            odd *= 2;
        }
    }

    ans = pow(3, N) - odd;

    cout << ans;

    return 0;
}