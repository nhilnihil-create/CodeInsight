#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<int> t(N), v(N);
    REP(i, N) cin >> t[i];
    REP(i, N) cin >> v[i];

    vector<double> left(N + 2), right(N + 2), vCon(N + 2);
    double sumTD = 0;
    int sumT = 0;
    REP(i, N + 2)
    {
        if (i == 0) 
        {
            left[i] = 0;
            right[i] = 0;
            vCon[i] = 0;
        }
        else if (i == N + 1)
        {
            left[i] = sumTD;
            right[i] = sumTD;
            vCon[i] = 0;
        }
        else
        {
            left[i] = sumTD;
            right[i] = sumTD + t[i - 1];
            vCon[i] = (double)v[i - 1];
            sumTD += (double)t[i - 1];
            sumT += t[i - 1];
        }
    }
  
    vector<double> vMax(2 * sumT + 1);
    REP(i, 2 * sumT + 1)
    {
        double x = i / 2.0;
        vMax[i] = 100.0;
        REP(j, N + 2)
        {
            double y;
            if (x >= 0 && x <= left[j])
            {
                y = vCon[j] + left[j] - x;
            }
            else if (x >= left[j] && x <= right[j])
            {
                y = vCon[j];
            }
            else
            {
                y = vCon[j] + x - right[j];
            }
            vMax[i] = min(vMax[i], y);
        }
    }
    double ans = 0;
    REP(i, 2 * sumT)
    {
        ans += 0.25 * (vMax[i] + vMax[i + 1]);
    }

    cout << fixed;
    cout << setprecision(10) << ans << endl;
}
