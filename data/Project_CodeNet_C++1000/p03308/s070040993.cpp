#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, abs(A[i] - A[j]));
        }
    }

    cout << ans << endl;
}