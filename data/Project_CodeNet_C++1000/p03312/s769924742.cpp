#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

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
    vector<ll> ruisekiNum(N + 1);
    for (int i = 0; i < N; i++)
    {
        ruisekiNum.at(i + 1) = ruisekiNum.at(i) + nums.at(i);
    }
    ll INF = 1e15;
    ll answer = INF;
    //(一つ目と二つ目) < i <= (三つ目と四つ目)で分け、それぞれの境界を二分探索
    vector<ll> hiPart(4);
    vector<ll> lowPart(4);
    for (int i = 2; i < N - 1; i++)
    {
        ll leftOk, rightOk;
        ll ok, ng;
        ok = i - 1;
        ng = 0;
        while (abs(ok - ng) > 1)
        {
            ll mid = ng + (ok - ng) / 2;
            if (ruisekiNum.at(mid) > ruisekiNum.at(i) - ruisekiNum.at(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        leftOk = ok;
        ok = N - 1;
        ng = i;
        while (abs(ok - ng) > 1)
        {
            ll mid = ng + (ok - ng) / 2;
            if (ruisekiNum.at(mid) - ruisekiNum.at(i) > ruisekiNum.at(N) - ruisekiNum.at(mid))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        rightOk = ok;
        hiPart.at(0) = ruisekiNum.at(leftOk);
        lowPart.at(1) = ruisekiNum.at(i) - ruisekiNum.at(leftOk);
        hiPart.at(2) = ruisekiNum.at(rightOk) - ruisekiNum.at(i);
        lowPart.at(3) = ruisekiNum.at(N) - ruisekiNum.at(rightOk);

        if(leftOk > 1)
        {
            leftOk--;
        }
        lowPart.at(0) = ruisekiNum.at(leftOk);
        hiPart.at(1) = ruisekiNum.at(i) - ruisekiNum.at(leftOk);
        if(rightOk > i + 1)
        {
            rightOk--;
        }
        lowPart.at(2) = ruisekiNum.at(rightOk) - ruisekiNum.at(i);
        hiPart.at(3) = ruisekiNum.at(N) - ruisekiNum.at(rightOk);
        answer = min(answer, max({hiPart.at(0), lowPart.at(1), hiPart.at(2), lowPart.at(3)}) - min({hiPart.at(0), lowPart.at(1), hiPart.at(2), lowPart.at(3)}));
        answer = min(answer, max({hiPart.at(0), lowPart.at(1), lowPart.at(2), hiPart.at(3)}) - min({hiPart.at(0), lowPart.at(1), lowPart.at(2), hiPart.at(3)}));
        answer = min(answer, max({lowPart.at(0), hiPart.at(1), hiPart.at(2), lowPart.at(3)}) - min({lowPart.at(0), hiPart.at(1), hiPart.at(2), lowPart.at(3)}));
        answer = min(answer, max({lowPart.at(0), hiPart.at(1), lowPart.at(2), hiPart.at(3)}) - min({lowPart.at(0), hiPart.at(1), lowPart.at(2), hiPart.at(3)}));
    }
    cout << answer << endl;
    return 0;
}
