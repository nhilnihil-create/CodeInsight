#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> x(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    vector<int> y(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> y[i];
    }

    for (int Z = X + 1; Z <= Y; Z++)
    {
        bool is_ok = true;
        for (int i = 0; i < N; i++)
        {
            if (Z <= x[i])
            {
                is_ok = false;
            }
        }
        for (int i = 0; i < M; i++)
        {
            if (Z > y[i])
            {
                is_ok = false;
            }
        }

        if (is_ok == true)
        {
            // printf("Z = %d\n", Z);
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return (0);
}