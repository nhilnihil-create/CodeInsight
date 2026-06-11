#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX_N = 100010;
int par[MAX_N], uniteRank[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums.at(i);
    }
    sort(nums.begin(), nums.end());
    ll answer1 = nums.at(nums.size() - 1);
    ll answer2 = nums.at(0);
    for (int i = 1; i < N - 1; i++)
    {
        if(min(answer2, answer1 - answer2) < min(nums.at(i), answer1 - nums.at(i)))
        {
            answer2 = nums.at(i);
        }
    }
    cout << answer1 << " " << answer2 << endl;
    return 0;
}
