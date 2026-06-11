#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int64_t gcd(int64_t p, int64_t q)
{
    if (p < q)
        swap(p, q);

    if (p % q == 0)
        return q;
    else
        return gcd(q, p % q);
}

int main()
{
    int A, B, K, count = 0;
    vector<int> list;
    cin >> A >> B >> K;
    int X = gcd(A, B);
    for (int i = 1; i <= X; i++)
        if (X % i == 0)
            list.push_back(i);
    cout << list[list.size() - K];
}