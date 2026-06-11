#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

ll cnt = 0;
ll N;
void dfs(ll v, bool flg3, bool flg5, bool flg7){
    if(v > N) return;
    if(flg3 && flg5 && flg7) cnt++;
    dfs(v*10 + 3, true, flg5, flg7);
    dfs(v*10 + 5, flg3, true, flg7);
    dfs(v*10 + 7, flg3, flg5, true);
}

int main(){

    cin >> N;
    dfs(0, false, false, false);
    cout << cnt << endl;

    
    return 0;
}