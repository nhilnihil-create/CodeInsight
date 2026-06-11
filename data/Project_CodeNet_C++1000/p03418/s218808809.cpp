#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
    
    ll count = 0;
    for (int b = K + 1; b <= N; b++) {
        int q = (int)(N / b);
        int r = N % b;
        count += (ll)(q * (b - K) + max(r - K + 1, 0));
        if (K == 0) count -= 1;
    }
    cout << count << endl;

    return 0;
}
