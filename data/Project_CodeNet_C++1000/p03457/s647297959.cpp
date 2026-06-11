#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> in(n, vector<int> (3, 0));
    bool res = true;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> in[i][j];
        }
    }

    if(n == 1)
    {
        cout << (in[0][1] + in[0][2] <= in[0][0] && 
            in[0][1] + in[0][2] % 2 == in[0][0] % 2 ? "Yes" : "No") << "\n";
    } else
    {
        for(int i = 0; i < n - 1; ++i)
        {
            if(abs(in[i+1][0] - in[i][0]) < 
                abs(in[i+1][1] - in[i][1]) + abs(in[i+1][2] - in[i][2])
                ||  (in[i][1] + in[i][2]) % 2 != in[i][0] % 2)
            {
                res = false;
            }
        }
        cout << (res ? "Yes" : "No") << "\n";
    }

    return 0;
}
