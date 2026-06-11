#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
typedef long long ll;
using namespace std;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main()
{
    ll N; cin >> N;
    vector<ll> A(5);
    ll mi = 1LL<<60;
    for (int i = 0; i < 5; ++i) cin >> A[i], mi = min(mi, A[i]);
    cout << (N + mi - 1) / mi + 4 << endl;
}
