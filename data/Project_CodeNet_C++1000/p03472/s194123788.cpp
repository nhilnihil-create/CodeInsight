#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, H;
    cin >> N >> H;

    vector<pii> as, bs;
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        as.emplace_back(a, i);
        bs.emplace_back(b, i);
    }

    sort(as.begin(), as.end(), greater<pii>());
    sort(bs.begin(), bs.end(), greater<pii>());

    pii bsum(0, -1);
    for(int i=0; i<N; i++)
    {
        if(bsum.first >= H)
        {
            cout << i << '\n';
            return 0;
        }
        if(bs[i].first < as[0].first) break;
        bsum.first += bs[i].first;
        bsum.second = i+1;
    }

    cout << (H - bsum.first + as[0].first - 1) / as[0].first + bsum.second << '\n';

    return 0;
}