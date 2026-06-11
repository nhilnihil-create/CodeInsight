#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;

template<class T>
vector<int> argsort(vector<T> v, vector<T> w){
    vector<int> index(v.size());
    iota(index.begin(), index.end(), 0);

    sort(index.begin(), index.end(),
            [&v, &w](const size_t &a, const size_t &b){
        if(v[a] == v[b]){
            return w[a] < w[b];
        }
        else{
            return v[a] < v[b];
        }
    });

    return index;
}

vector<ll> w(1100), s(1100), v(1100);
ll dp[1100][21000];

int main(){
    int N;
    cin >> N;
    vector<ll> su;
    for(int i = 0; i < N; i++){
        cin >> w[i] >> s[i] >> v[i];
        su.push_back(w[i] + s[i]);
    }

    vector<int> index = argsort<ll>(su, w);

    for(int i = 0; i < 1100; i++){
        for(int j = 0; j < 21000; j++){
            dp[i][j] = 0;
        }
    }

    dp[0][w[index[0]]] = v[index[0]];
    for(int i = 1; i < N; i++){
        ll ww = w[index[i]];
        ll vv = v[index[i]];
        ll ss = s[index[i]];

        for(int j = 0; j < 21000; j++){
            if(ss >= j && j + ww < 21000){
                dp[i][j+ww] = max(dp[i][j+ww], dp[i-1][j] + vv);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    ll res = 0;
    for(int j = 0; j < 21000; j++){
        res = max(res, dp[N-1][j]);
    }
    cout << res << endl;


    return 0;
}