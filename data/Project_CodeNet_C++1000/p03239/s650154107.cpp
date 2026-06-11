#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> c(N);
    vector<int> t(N);
    for (int i = 0; i < N; i++)
        cin >> c[i] >> t[i];
    int cost = mod;
    for (int i = 0; i < N; i++)
    {
        if (c[i] < cost && t[i] <= T)
            cost = c[i];  
    }
    if (cost == mod)
        cout << "TLE";
    else
        cout << cost;
}