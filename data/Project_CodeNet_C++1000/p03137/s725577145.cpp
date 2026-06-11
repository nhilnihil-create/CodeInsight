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

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<int> dist(m-1);
    for(int i = 0; i < m-1; i++){
        dist[i] = x[i+1] - x[i]; 
    }
    sort(dist.rbegin(), dist.rend());
    int ans = 0;
    for(int i = n-1; i < m-1; i++){
        ans += dist[i];
    }
    cout << ans << endl;
    return 0;
}