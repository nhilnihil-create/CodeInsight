#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(max(A * 10 + B + C, A + B * 10 + C), A + B + C * 10);
}