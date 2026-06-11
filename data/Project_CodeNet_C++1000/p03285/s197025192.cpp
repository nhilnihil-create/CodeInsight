#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D, C, Sum, flag = 0;
    cin >> N;
    vector<int> v;

    if (N >= 4)
    {
        for (int i = 0; 4 * i <= 100; i++)
        {

            for (int a = 0; 7 * a <= 100; a++)
            {
                Sum = 4 * i + 7 * a;
                v.push_back(Sum);
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == N)
            {
                cout << "Yes";
                flag = 1;
                break;
            }

            else
            {
                flag = 2;
            }
        }
    }

    if (N < 4)
    {
        flag = 2;
    }

    if (flag == 2)
    {
        cout << "No";
    }
}