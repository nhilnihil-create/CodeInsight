#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int N;
    cin >> N;
    vector<int> C(N - 1);
    vector<int> S(N - 1);
    vector<int> F(N - 1);

    for (int i = 0; i < N - 1; i++)
        cin >> C[i] >> S[i] >> F[i];

    for (int start = 0; start < N - 1; start++)
    {
        int time = 0;
        for (int i = start; i < N - 1; i++)
        {
            if (time < S[i])
                time = S[i];
            else if (time % F[i] != 0)
                time = time + F[i] - (time % F[i]);
            time += C[i];
        }
        cout << time << endl;
    }

    cout << 0;
}