#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> X(N), sorted(N);
    rep(0, i, N)
    {
        cin >> X.at(i);
        sorted.at(i) = X.at(i);
    }
    sort(all(sorted));
    ll med1 = sorted.at(N / 2);
    ll med2 = sorted.at(N / 2 - 1);
    rep(0, i, N)
    {
        if (X.at(i) >= med1)
        {
            cout << med2 << endl;
        }
        else
        {
            cout << med1 << endl;
        }
    }
}