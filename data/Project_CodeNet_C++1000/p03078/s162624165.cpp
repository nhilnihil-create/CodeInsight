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
#define INF 1000000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    ll X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i,X) cin >> A[i];
    rep(i,Y) cin >> B[i];
    rep(i,Z) cin >> C[i];
    priority_queue<ll, vector<ll>, greater<ll>> que;
    vector<ll> AB;
    rep(i,X)rep(j,Y){
        AB.push_back(A[i] + B[j]);
    }
    sort(AB.begin(), AB.end());
    sort(C.begin(), C.end());
    reverse(AB.begin(), AB.end());
    reverse(C.begin(), C.end());
    ll N = AB.size();
    rep(i,N){
        ll ab = AB[i];
        if(que.size()==K){
            if(que.top() >= ab + C[0]) break;
        }
        rep(j,Z){
            ll abc = ab + C[j];
            ll q_n = que.size();
            if(q_n == K){
                ll smaller = que.top();
                if(smaller < abc){
                    que.pop();
                    que.push(abc);
                }
                else break;
            }
            else{
                que.push(abc);
            }
        }
    }
    vector<ll> ans(K);
    rep(i,K){
        ll abc = que.top();que.pop();
        ans[K-1-i] = abc;
    }
    rep(i,K) cout << ans[i] << endl;
}