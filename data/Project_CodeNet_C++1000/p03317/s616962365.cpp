#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N, K;
    cin >> N >> K;
    ll out = (N - 1) / (K - 1);
    if((N-1)%(K-1)!= 0)
        out++;
    cout << out << endl;
    return 0;
}