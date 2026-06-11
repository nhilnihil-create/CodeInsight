#include <iostream>
#include <algorithm>
using namespace std;

long long N,M;
void input()
{
    cin >> N >> M;
}

void solve()
{
    if (N >= 2 && M >= 2){
        cout << (N-2) * (M-2) << endl;
    } else if (N == 1 && M == 1) {
        cout << 1 << endl;
    } else {
        cout << max(N,M) - 2 << endl;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}