#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M, X, tmp;
    cin >> N >> M >> X;
   
    vector<bool> list(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        list[tmp] = true;
    }
    vector<int> map(N + 1);
    for (int i = 1; i < N + 1; i++)
    {
        map[i] = map[i - 1];
        if(list[i])
            map[i]++;
    }
    cout << min(map[X], map[N] - map[X]);
}