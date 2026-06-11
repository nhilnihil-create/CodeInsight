#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int res =
        A * N < B ? A * N : B;
    cout << res << endl;
}