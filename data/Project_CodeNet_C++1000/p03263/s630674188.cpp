#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
#define MOD int(1e9 + 7)
#define INF (long long)(1e18)

int main()
{
    long long H, W;
    vector<vector<long long>> A;

    cin >> H >> W;
    for (long long i = 0; i < H; i++)
    {
        vector<long long> tv;
        for (long long j = 0; j < W; j++)
        {
            long long t;
            cin >> t;
            tv.push_back(t);
        }
        A.push_back(tv);
    }

    long long h = 0;
    long long w = 0;
    long long d = 1;
    vector<vector<long long>> xy;
    for (long long i = 0; i < H; i++)
    {
        h = i;
        for (long long j = 0; j < W; j++)
        {
            xy.push_back(vector<long long>{h, w});
            w += d;
        }
        d *= (-1);
        w += d;
    }

    long long b = -1;
    vector<vector<long long>> output;
    for (long long i = 0; i < xy.size(); i++)
    {
        if (A[xy[i][0]][xy[i][1]] % 2 == 1)
        {
            if (b == -1)
                b = i;
            else
            {
                for (long long j = b; j < i; j++)
                    output.push_back(vector<long long>{xy[j][0], xy[j][1], xy[j + 1][0], xy[j + 1][1]});
                b = -1;
            }
        }
    }

    cout << output.size() << endl;
    for (long long i = 0; i < output.size(); i++)
    {
        cout << output[i][0] + 1 << ' ';
        cout << output[i][1] + 1 << ' ';
        cout << output[i][2] + 1 << ' ';
        cout << output[i][3] + 1 << endl;;
    }
}