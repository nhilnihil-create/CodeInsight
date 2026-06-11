#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, H;
    cin >> N >> H;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i) >> b.at(i);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int res = 0;
    int i = 0;
    while (i < N && a.at(0) < b.at(i))
    {
        int bi = b.at(i);
        i++;

        H -= bi;
        res++;
        if (H <= 0)
        {
            cout << res << endl;
            return 0;
        }
    }

    int a0 = a.at(0);
    res += (H + a0 - 1) / a0;
    cout << res << endl;
}