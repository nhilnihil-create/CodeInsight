#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    int counter = 0;
    for (int i = 1; i < N; i++)
    {
        if (A[i - 1] == A[i])
        {
            counter++;
            A[i] = -1;
        }
    }
    cout << counter << endl;
}