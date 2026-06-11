#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    Vvec<ll> a(N, vector<ll>(N));
    for(auto& v: a){
        for(auto& x: v) cin >> x;
    }

    vector<ll> dp(1<<N);
    for(int i=0; i<(1<<N); i++){
        for(int j=0; j<N; j++){
            for(int k=j+1; k<N; k++){
                if((i>>j)&(i>>k)&1) dp[i] += a[j][k];
            }
        }
    }

    for(int i=0; i<(1<<N); i++){
        for(int j=i; j>0; j=(j-1)&i){
            dp[i] = max(dp[i], dp[j] + dp[i^j]);
        }
    }

    cout << dp[(1<<N)-1] << endl;
}