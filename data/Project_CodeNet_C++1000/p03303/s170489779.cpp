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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll m, ll n)
{
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

int main()
{
    string S;
    int w;

    cin >> S >> w;

    for(int i=0; i<S.size(); i=i+w){
        cout << S[i];
    }
    cout << endl;
    return 0;
}