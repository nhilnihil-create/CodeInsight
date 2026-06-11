#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
    using tsii = tuple<string, int, int>;
    using vtsii = vector<tsii>;
    int N, b;
    string a;
    cin >> N;
    vtsii v;
    rep(i, N)
    {
        cin >> a >> b;
        v.push_back(make_tuple(a, b, i + 1));
        get<1>(v.at(i)) *= -1;
    }
    sort(v.begin(), v.end());

    rep(i, N)
    {
        cout << get<2>(v.at(i)) << endl;
    }
}