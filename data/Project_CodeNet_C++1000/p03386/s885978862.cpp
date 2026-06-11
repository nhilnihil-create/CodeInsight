#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;
    for (int i = A; i < A + K; i++)
        if (i <= B)
            cout << i << endl;
    
    
    for (int i = B - K + 1; i <= B; i++)
        if (i > A + K - 1)
            cout << i << endl;
}