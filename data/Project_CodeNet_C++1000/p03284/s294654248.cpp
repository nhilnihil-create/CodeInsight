#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int N, K;
    cin >> N >> K;
    cout << (N % K == 0 ? 0 : 1);
}