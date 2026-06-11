#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

bool isPrime(const ll n)
{
    if (n < 2) return false;
    if (n == 2) return true;

    bool flag = true;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    ll N;
    cin >> N;

    const ll MAXP = 55555;
    vector<ll> primeVec;
    REP(i, MAXP)
    {
        if(isPrime(i)) 
        {
            primeVec.push_back(i);
        }
    }
    vector<ll> ans;
    REPV(it, primeVec)
    {
        if (*it % 5 == 1)
        {
            ans.push_back(*it);
        }
    }
    REP(i, N)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
