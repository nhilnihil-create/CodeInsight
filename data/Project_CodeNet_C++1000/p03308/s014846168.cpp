#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N;

    cin >> N;

    vector<int> A(N);

    rep(i, N)
            cin >> A[i];

    sort(A.begin(), A.end());

    cout << A.back() - A.front() << endl;

    return 0;
}