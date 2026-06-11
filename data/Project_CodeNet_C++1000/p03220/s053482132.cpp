#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Mat = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5+10;

int main(){
    int n,t,a;
    cin >> n >> t >> a;
    vi h(n);
    rep(i, n) cin >> h[i];

    double diff_min = 1e5;
    int ans = 0;
    rep(i,n){
        double temp = t - h[i]*0.006;
        double diff = fabs(temp - a);
        if(diff_min > diff){
            diff_min = diff;
            ans = i+1;
        }
    }
    cout(ans);
    return 0;
}