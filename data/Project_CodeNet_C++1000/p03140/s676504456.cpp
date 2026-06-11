#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    string A, B, C;
    cin >> N;
    cin >> A >> B >> C;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != B[i] && B[i] != C[i] && A[i] != C[i])
        {
            ans += 2;
        }
        else if (A[i] == B[i] && B[i] == C[i] && A[i] == C[i])
        {
            ans += 0;
        }
        else
        {
            ans += 1;
        }
    }
    cout << ans << endl;
}
