#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pe = pair<ll, ll>;

vector<pe> prime_factorize(ll num)
{
    vector<pe> result;

    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i != 0)
            continue;
        ll e = 0;

        while (num % i == 0)
        {
            e++;
            num /= i;
        }

        result.push_back({i, e});
    }

    if (num != 1)
        result.push_back({num, 1});
    return result;
}


int main(void)
{
    int N;
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i+=2)
    {
        vector<pe> result = prime_factorize(i);
        ll count = 1;
        for(auto elem : result){
            count *= (elem.second + 1);
        }

        if(count == 8) ans++;
    }
    cout << ans << endl;
    
    return 0;
}