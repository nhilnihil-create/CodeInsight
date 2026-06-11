#include <bits/stdc++.h>
using namespace std;

int A[300005];

void solve(int L, int lim, int a, int b)
{
    if(lim == 0)
        return;

    a = min(a, lim - b + 1);

    for(int i=lim-a+1; i<=lim; i++)
        A[i] = L++;
    
    solve(L, lim-a, a, b-1);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    if(1LL * a * b < n || a + b > n + 1)
    {
        cout << -1 << "\n";
        return 0;
    }

    solve(1, n, a, b);

    for(int i=1; i<=n; i++)
        cout << A[i] << " ";

    return 0;
}
