#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, dev;
    cin >> N;
    for(int n = N; n != 0; n /= 10)
        dev += n % 10;
    (N % dev == 0) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}