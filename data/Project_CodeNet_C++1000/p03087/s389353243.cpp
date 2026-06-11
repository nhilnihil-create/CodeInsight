#include <bits/stdc++.h>

using namespace std;

int PSA[(int)1e5 + 5];
int A[(int)1e5 + 5];

int main()
{
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    for (int i = 1; i <= (int)s.length() - 1; i++)
    {
        A[i] = ((s[i - 1] == 'A' && s[i] == 'C') ? 1 : 0);
    }
    for (int i = 1; i <= s.length() + 4; i++)
    {
        PSA[i] += PSA[i - 1] + A[i];
    }
    for (; Q > 0; Q--)
    {
        int l, r; cin >> l >> r;
        int result = PSA[r] - PSA[l - 1];
        if (A[r] == 1) result--;
        cout << result << "\n";
    }
}