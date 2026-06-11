#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    deque<ll> D;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        ll v;
        cin >> v;
        D.push_back(v);
    }

    ll ans = 0;
    for (int i = 0; i <= min(N, K); i++)
    {
        ll sum_r = 0;
        for (int l = 0; l <= i; l++)
        {

            int r = i - l;

            v<ll> hand;
            ll sum = 0;

            for (int j = 0; j < l; j++)
            {
                hand.push_back(D[j]);
            }
            for (int j = 0; j < r; j++)
            {
                hand.push_back(D[D.size() - 1 - j]);
            }
            if (hand.size() > 0)
            {
                sort(ALL(hand), greater<int>());

                for (int j = 0; j < K - i; j++)
                {
                    if (hand[hand.size() - 1] < 0)
                        hand.pop_back();
                }

                for (int j = 0; j < hand.size(); j++)
                {
                    sum += hand[j];
                }
                sum_r = max(sum, sum_r);
            }
        }
        ans = max(sum_r, ans);
    }

    cout << ans << endl;
    return 0;
}