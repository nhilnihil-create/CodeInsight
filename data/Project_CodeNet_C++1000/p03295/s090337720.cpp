#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int INF = 1<<30;

int main(){
    int n, m;
    cin >> n >> m;
    VI g(n, INF);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        chmin(g[a], b);
    }

    int ans = 0, left = 0;
    while(left < n){
        if (g[left] == INF){
            left++;
            continue;
        }

        ans++;
        int i = left+1, right = g[left];
        while(i < right){
            if (g[i] != INF) chmin(right, g[i]);
            i++;
        }
        left = i;
    }
    cout << ans << endl;
    return 0;
}