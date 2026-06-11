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
    vector<ll> w(N), s(N), v(N), idx(N);
    for(int i=0; i<N; i++){
        cin >> w[i] >> s[i] >> v[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int i, int j){
        if(w[i]+s[i]==w[j]+s[j]) return i<j;
        return w[i]+s[i] < w[j]+s[j];
    });

    const int W = 2e4+10;
    vector<ll> dp(W);
    for(int i=0; i<N; i++){
        for(int j=W-1; j>=0; j--){
            int k = idx[i];
            if(j-w[k]>=0 && j<=w[k]+s[k]) dp[j] = max(dp[j], dp[j-w[k]] + v[k]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}