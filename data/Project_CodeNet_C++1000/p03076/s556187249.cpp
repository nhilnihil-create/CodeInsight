#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, D, E, a = 0;
    cin >> A >> B >> C >> D >> E;
    vector<int> v = {A, B, C, D, E};
    vector<int> b;

    do
    {
        int Sum = v[0];

        for (int i = 0; i < v.size(); i++)
        {

            if (i == 0 && Sum % 10 != 0)
            {
                a = (v[i] / 10 + 1) * 10 - v[i];
                Sum += a;
                continue;
            }

            if (i == 0 && Sum % 10 == 0)
            {
                continue;
            }

            if (Sum % 10 == 0)
            {
                Sum += v[i];
                continue;
            }

            if (Sum % 10 != 0 && i != 0)
            {
                a = (v[i - 1] / 10 + 1) * 10 - v[i - 1];
                Sum += a + v[i];

                continue;
            }
        }
        b.push_back(Sum);

    } while (next_permutation(v.begin(), v.end()));

    auto iter = min_element(b.begin(), b.end());

    cout << *iter << endl;
}