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
    ll answer = 0;
    vector<pll> remains; // B, A
    ll evenCount = 0;
    ll bNeedReduce = 0;
    for (int i = 0; i < N; i++)
    {
        ll A, B;
        cin >> A >> B;
        if (A < B)
        {
            answer += A;
            bNeedReduce += B - A;
        }
        else if (A == B)
        {
            evenCount += A;
        }
        else
        {
            remains.emplace_back(B, A);
        }
    }
    if(bNeedReduce > 0)
    {
        answer += evenCount;
    }
    sort(remains.begin(), remains.end(), greater<pll>());
    for (auto remain : remains)
    {
        ll A, B;
        tie(B, A) = remain;
        bNeedReduce -= A - B;
        answer += A - B;
        if (bNeedReduce == 0)
        {
            break;
        }
        answer += B;
    }
    cout << answer << endl;
    return 0;
}
