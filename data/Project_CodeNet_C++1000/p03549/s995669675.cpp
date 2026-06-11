#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(void)
{
    int N, M;
    cin >> N >> M;
    int singleWait = M * 1900 + (N - M) * 100;


    int result = (1 << M) * singleWait;

    cout << result << endl;

    return 0;
}
