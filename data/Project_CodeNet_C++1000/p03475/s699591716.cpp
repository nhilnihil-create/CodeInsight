#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> C(N - 1), S(N - 1), F(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }

    for (int i = 0; i < N; i++)
    {
        int t = 0;
        for (int j = i; j < N - 1; j++)
        {
            int Cj = C.at(j), Sj = S.at(j), Fj = F.at(j);
            if (t < Sj)
            {
                t = Sj;
            }
            else if (t % Fj != 0)
            {
                t += Fj - (t % Fj);
            }
            t += Cj;
        }
        cout << t << endl;
    }
}