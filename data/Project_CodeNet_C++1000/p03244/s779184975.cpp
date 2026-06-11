#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long int;

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    map<ll, ll> odd;
    map<ll, ll> even;

    for (ll i = 0; i < N; i += 2)
    {
        odd[A[i]] += 1;
    }

    for (ll j = 1; j < N; j += 2)
    {
        even[A[j]] += 1;
    }

    vector<pair<ll, ll>> o;
    for (auto &&elem : odd)
    {
        o.push_back({elem.first, elem.second});
    }

    vector<pair<ll, ll>> e;
    for (auto &&elem : even)
    {
        e.push_back({elem.first, elem.second});
    }
    o.push_back({0, 0});
    e.push_back({0, 0});

    sort(o.begin(), o.end(), [](const pair<ll, ll> lhs, const pair<ll, ll> rhs) {
        return lhs.second > rhs.second;
    });
    sort(e.begin(), e.end(), [](const pair<ll, ll> lhs, const pair<ll, ll> rhs) {
        return lhs.second > rhs.second;
    });
    
    ll ans = INT_MAX;
    if (o[0].first != e[0].first) {
        ans = min(ans, N - o[0].second - e[0].second);
    }
    if (o[0].first != e[1].first) {
        ans = min(ans, N - o[0].second - e[1].second);
    }
    if (o[1].first != e[0].first) {
        ans = min(ans, N - o[1].second - e[0].second);
    }
    if (o[1].first != e[1].first) {
        ans = min(ans, N - o[1].second - e[1].second);
    }
    if (ans == INT_MAX) {
        ans = N / 2;
    }
    cout << ans << endl;
}