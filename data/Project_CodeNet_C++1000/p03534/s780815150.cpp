#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    ll a = 0;
    ll b = 0;
    ll c = 0;
    rep (i, S.size()) {
        if (S[i] == 'a') {
            a++;
        }
        if (S[i] == 'b') {
            b++;
        }
        if (S[i] == 'c') {
            c++;
        }
    }

    if (abs(a-b) >= 2 || abs(b-c) >= 2 || abs(c-a) >= 2) {
        NO;
    } else {
        YES;
    }
    return 0;
}