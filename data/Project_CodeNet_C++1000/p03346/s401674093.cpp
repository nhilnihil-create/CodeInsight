#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i,N) cin >> P[i];
    vector<int> Q(N);
    rep(i,N){
        Q[P[i]-1] = i;
    }
    ll res = 0;
    ll cnt = 0;
    rep(i,N-1){
        if(Q[i] < Q[i+1]) cnt++;
        else{
            res = max(res,cnt);
            cnt = 0;
        }
    }
    res = max(res,cnt);
    res++;
    cout << N - res << endl;
}