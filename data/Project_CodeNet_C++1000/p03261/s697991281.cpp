#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<string> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    bool x = true;
    for (int i = 1; i < N; i++)
        if (list[i - 1][list[i - 1].size() - 1] != list[i][0])
            x = false;
    sort(list.begin(), list.end());
    for (int i = 1; i < N; i++)
        if (list[i - 1] == list[i])
            x = false;
    cout << (x ? "Yes" : "No");
}