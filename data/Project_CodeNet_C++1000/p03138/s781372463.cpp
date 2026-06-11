#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    ll A[N];
    REP(i, N) cin >> A[i];
    const int digit = 40;
    ll countDigit[digit] = {0};
    REP(i, N)
    {
        ll num = A[i];
        int count = 0;
        while(num > 0)
        {
            if (num % 2 == 1) countDigit[count]++;
            count++;
            num /= 2;
        }
    }

    ll num = K + 1;
    bool binaryK[digit] = {false};
    int count = 0;
    while(num > 0)
    {
        if (num % 2 == 1) binaryK[count] = true;
        count++;
        num /= 2;
    }

    ll score[digit] = {0};
    REP(i, digit)
    {
        if (binaryK[i])
        {
            for (int j = 0; j < i; ++j) score[i] += (ll)pow(2, j) * max(countDigit[j], N - countDigit[j]);
            score[i] += (ll)pow(2, i) * countDigit[i];
            for (int j = i + 1; j < digit; ++j)
            {
                if (binaryK[j]) score[i] += (ll)pow(2, j) * (N - countDigit[j]);
                else score[i] += (ll)pow(2, j) * countDigit[j];
            }
        }
    }

    ll ans = 0;
    REP(i, digit) ans = max(ans, score[i]);
    cout << ans << endl;
}
