#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;
    int *P;
    P = new int[N];
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    sort(P, P + N);
    int countA = 0;
    int countB = 0;
    int countlargerB = 0;
    for (int i = 0; i < N; i++)
    {
        if (P[i] <= A)
        {
            countA++;
        }
        if (P[i] >= A + 1 && P[i] <= B)
        {
            countB++;
        }
        if (P[i] >= B + 1)
        {
            countlargerB++;
        }
    }
    cout << min(countlargerB, min(countA, countB)) << endl;
    return 0;
}