#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> AB(N);
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        AB.at(i) = make_pair(a, b);
    }

    sort(AB.begin(), AB.end());
    ll ans = 0;
    for(int i=0; i<N; i++)
    {
        if(AB[i].second < M)
        {
            M -= AB[i].second;
            ans += 1LL * AB[i].first * AB[i].second;
        }
        else
        {
            ans += 1LL * AB[i].first * M;
            break;
        }
    }
    cout << ans << endl;


    return 0;
}
