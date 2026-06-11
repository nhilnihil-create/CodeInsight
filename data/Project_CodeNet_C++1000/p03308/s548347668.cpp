#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    sort(list.begin(), list.end());
    cout << abs(list[0] - list[N - 1]);
}