#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1145141919
typedef long long int ll;
using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x;
    return is;
}

ll gcd(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    while (m != n)
    {
        if (m > n)
            m = m - n;
        else
            n = n - m;
    }
    return m;
}

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

int ctoi(const char c)
{
    if ('0' <= c && c <= '9')
        return (c - '0');
    return -1;
}

int main(){
    ll n, p;
    cin >> n >> p;
    vector<ll> sosuu;
    sosuu.push_back(2);

    if(n==1){
        cout << p << endl;
        return 0;
    }

    for (int i = 3; i <= 1000000; i += 2)
    {
        if (p % i == 0)
        {
            bool flg = true;
            for (int j = 0; j < sosuu.size(); ++j)
            {
                if (i % sosuu[j] == 0)
                    flg = false;
            }
            if (flg == true)
                sosuu.push_back(i);
        }
    }

    ll ans=1;
    //cout << sosuu.size() << endl;
    REP(i, sosuu.size()){
        //cout << sosuu[i] << endl;

        ll res_p = p;
        ll divider = pow(sosuu[i], n);
        while(res_p % divider ==0){
            res_p /= divider;
            ans *= sosuu[i];
        }    
    }

    cout << ans << endl;
    return 0;

}