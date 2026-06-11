#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int N, M, X, Y, tmp;
    cin >> N >> M >> X >> Y;
    int Xmax = X, Ymin = Y;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        Xmax = max(Xmax, tmp);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        Ymin = min(Ymin, tmp);
    }
    cout << (Xmax < Ymin ? "No War" : "War");
}