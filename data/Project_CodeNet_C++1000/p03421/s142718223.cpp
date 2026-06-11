#include <iostream>
#include <algorithm>

using namespace std;

long long N, A, B;

void solve()
{
    if (N < A + B - 1 || A * B < N) {
        cout << -1;
        return;
    }
    
    while (N > 0) {
	long long x = min(A, N - B + 1);
	for (long long i = N - x + 1; i <= N; ++i) cout << i << " ";
	N -= x;
        --B;
    }
}

int main()
{
    cin >> N >> A >> B;
    solve();

    return 0;
}