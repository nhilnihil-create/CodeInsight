
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    for (auto &p : P)
        cin >> p;

    vector<int> C(N + 1);
    for (int p : P)
    {
        C[p] = C[p - 1] == 0 ? 1 : C[p - 1] + 1;
    }

    cout << N - *max_element(C.begin(), C.end())
         << endl;

    return 0;
}
