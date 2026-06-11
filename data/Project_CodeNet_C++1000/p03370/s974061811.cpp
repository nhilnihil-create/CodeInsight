#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, X, i, ans;
    cin >> N >> X;
    vector<int> vec(N);
    for (i = 0; i < N; i++)
    {
        cin >> vec.at(i);
        X -= vec.at(i);
    }
    ans += N;

    sort(vec.begin(), vec.end());
    ans += (X / *vec.begin());
    cout << ans << endl;
}