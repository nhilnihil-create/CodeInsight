#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<int> count_w(N);
    int cnt_w = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (S.at(i) == '.')
            cnt_w++;
        count_w.at(i) = cnt_w;
    }

    int res = N + 1;
    int cnt = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (S.at(i) == '#')
        {
            res = min(res, cnt + count_w.at(i + 1));
            cnt++;
        }
    }
    cout << min(res, cnt) << endl;
    return 0;
}
