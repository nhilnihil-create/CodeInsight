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
    long long int a, ans = 0;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        ans += a - 1;
    }

    cout << ans;

    return 0;
}

