#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<int> V(N), C(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    for (int i = 0; i < N; i++)
        cin >> C[i];
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        list[i] = V[i] - C[i];
    sort(list.begin(), list.end());
    reverse(list.begin(), list.end());
    int ans = 0;
    int i = 0;
    while (list[i] > 0)
    {
        ans += list[i];
        i++;
    }
    cout << ans;
}