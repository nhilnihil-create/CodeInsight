//
// Created by yamunaku on 2019/12/20.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    // CFS;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> eList(n); // 隣接リスト
    vector<vector<int>> rList(n); // 隣接リスト
    vector<int> inDeg(n, 0); // 入次数
    int u, v;
    for(int i = 0; i < n - 1 + m; i++){
        cin >> u >> v;
        u--, v--;
        eList[u].push_back(v);
        rList[v].push_back(u);
        inDeg[v]++;
    }

    queue<int> zeroQue; // 入次数 0 の頂点でまだ取られていないものを入れる
    for(int i = 0; i < n; i++){
        if(inDeg[i] == 0) zeroQue.push(i);
    }

    vector<int> result; // トポロジカルソートの結果を入れる
    while(!zeroQue.empty()){
        int u = zeroQue.front(); // 入次数 0 の頂点 u を 1 つ取る
        zeroQue.pop();

        result.push_back(u);
        for(int v:eList[u]){ // u を始点とする辺すべてについて、
            inDeg[v]--; // 終点の入次数を減らす
            if(inDeg[v] == 0) zeroQue.push(v); // 入次数が 0 になったら取ることができる
        }
    }

    vi ans(n);
    vi depth(n);
    ans[result[0]] = depth[result[0]] = 0;
    repl(i, 1, n){
        int ma = -1, idx = -1;
        for(auto &nx:rList[result[i]]){
            if(ma < depth[nx]){
                ma = depth[nx];
                idx = nx;
            }
        }
        ans[result[i]] = idx + 1;
        depth[result[i]] = i;
    }
    rep(i, n){
        cout << ans[i] << endl;
    }
    return 0;
}