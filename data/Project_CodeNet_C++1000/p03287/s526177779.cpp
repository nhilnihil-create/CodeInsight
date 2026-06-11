#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums.at(i);
    }
    vector<ll> ruisekiMod(N + 1);
    map<ll, ll> ruisekiModCount;
    for(int i = 0; i < N; i++)
    {
        ruisekiMod.at(i + 1) = (ruisekiMod.at(i) + nums.at(i)) % M;
        ruisekiModCount[ruisekiMod.at(i + 1)]++;
    }
    ll answer = 0;
    for(int i = 0; i < N; i++)
    {
        ll currentMod = ruisekiMod.at(i);
        answer += ruisekiModCount[currentMod];
        ruisekiModCount[ruisekiMod.at(i + 1)]--;
    }
    cout << answer << endl;
    return 0;
}
