#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, X, tmp, sum = 0;
    cin >> N >> X;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        list[i] = tmp;
        sum += list[i];
    }
    sort(list.begin(), list.end());
    cout << N + (X - sum) / list[0];
}