#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    if (2 * K == N || (2 * K - 1) == N || 2 * K < N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
