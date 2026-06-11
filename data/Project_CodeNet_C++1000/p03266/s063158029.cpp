#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1 << 21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// 0108c
int main(){
    ll n, k;
    cin >> n >> k;
    if (k%2){
        ll tmp = n/k;
        cout << tmp*tmp*tmp << endl;
    }else{
        ll htmp = 2 * n/k;
        ll tmp = n/k;
        cout << tmp*tmp*tmp + (htmp-tmp)*(htmp-tmp)*(htmp-tmp) << endl;
    }
    return 0;
}