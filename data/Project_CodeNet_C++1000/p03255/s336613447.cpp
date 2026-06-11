#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using ulli = unsigned long long int;

int main() {
    ulli N, X;
    cin >> N >> X;
    vector<ulli> x(N + 1, 0);
    for (uint i = 0; i < N; i++) {
	cin >> x[i + 1];
    }
    
    for (uint i = 0; i < N; i++) {
	x[i + 1] += x[i];
    }

    ulli ans = numeric_limits<ulli>::max();

    for (int i = 1; i <= N; i++) {
	ulli cost = X * i;
	ulli k = 5;
	ulli t = 1;
	for (int j = N; j > 0; j -= i) {
	    int end = max(j - i, 0);
	    cost += k * (x[j] - x[end]);
	    t++;
	    k = 2 * t + 1;
	}
	ans = min(ans, cost);
    }
    cout << ans + N * X << endl;
    return 0;
}
