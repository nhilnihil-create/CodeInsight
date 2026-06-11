#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 86;

long long int luca[MAX_N + 3];

int main()
{
    int N;
    cin >> N;
    luca[0] = 2;
    luca[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        luca[i] = luca[i - 1] + luca[i - 2];
    }
    cout << luca[N] << endl;
}
