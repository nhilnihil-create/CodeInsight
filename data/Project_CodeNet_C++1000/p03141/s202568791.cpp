#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;
//互いに最も差の大きいものをとればよい??
// -> 相手がべらぼうに多い
//差がない場合は、一番大きいもの?
//50 50 
//60 0


int main(){
    ll N;
    cin >> N;
    vector <ll> a(N);
    vector <ll> b(N);
    vector <ll> ab(N);

    REP(i,N)
    {
        cin >> a[i] >> b[i];
        ab[i] = a[i] + b[i];
    }
    sort(ab.rbegin(), ab.rend());

    ll res = 0;
    for(int i = 0; i < N; i += 2)
    {
        res += ab[i];
    }
    for(int i = 0; i < N; ++i)
    {
        res -= b[i];
    }
    cout << res << endl;
    return 0;    
}

