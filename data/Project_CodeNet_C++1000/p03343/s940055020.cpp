#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    int A[N];
    set<int> s;
    rep(i, N){
        cin >> A[i];
        s.insert(A[i]);
    }
    //vec[i]:=Aに含まれる整数でi番目(同じ数字は一つと考える)のもの
    vector<int> vec;
    for(auto &e: s){
        vec.pb(e);
    }
    //使えない場所のインデックス
    vector<int> used;
    used.pb(-1), used.pb(N);
    int ans = INT_MAX;
    //最小値としてvec[i]を取る場合
    rep(i, vec.size()){
        vector<int> tog;
        //区間(used[j], used[j+1])を探索
        rep(j, used.size()-1){
            vector<int> tmp;
            int n = used[j+1]-used[j]-1;
            if(n < K) continue;
            rep2(k, used[j]+1, used[j+1]-1){
                tmp.pb(A[k]);
            }
            sort(tmp.begin(), tmp.end());
            rep(k, n-K+1){
                tog.pb(tmp[k]);
            }
        }
        if(tog.size() < Q) continue;
        sort(tog.begin(), tog.end());
        ans = min(ans, tog[Q-1]-tog[0]);
        //A[j]=vec[i]となるjをusedに追加
        rep(j, N){
            if(A[j] == vec[i]) used.pb(j);
        }
        sort(used.begin(), used.end());
    }
    cout << ans << endl;
}