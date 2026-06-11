#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<int> E(N), W(N);
    if (S[0] == 'E')
    {
        E[0] = 1;
        W[0] = 0;
    }
    else
    {
        E[0] = 0;
        W[0] = 1;
    }
    for (int i = 1; i < N; ++i)
    {
        if (S[i] == 'E')
        {
            E[i] = E[i - 1] + 1;
            W[i] = W[i - 1];
        }
        else
        {
            E[i] = E[i - 1];
            W[i] = W[i - 1] + 1;
        }
    }
    int ans = E[N - 1] - E[0];
    for (int i = 0; i < N; ++i)
    {
        int toE, toW;
        if (i == 0)
        {
            toE = 0;
        }
        else
        {
            toE = W[i - 1];
        }
        if (i == N - 1)
        {
            toW = 0;
        }
        else
        {
            toW = E[N - 1] - E[i];
        }
        ans = min(ans, toE + toW);
    }
    cout << ans << endl;
}