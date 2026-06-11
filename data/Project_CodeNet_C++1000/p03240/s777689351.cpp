#include <bits/stdc++.h>
#define INF pow(10, 9) + 7
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

void solve(){
	
	ll n, s, H;
	vl x(105), y(105), h(105);
	ll z = 0;

    cin >> n;
    rep(i, n){
        cin >> x[i] >> y[i] >> h[i];
        if(h[i]) s = i;
    }
	
    rep(i, 101){
        rep(j, 101){
            H = h[s] + abs(x[s] - i) + abs(y[s] - j);
            bool flg = 1;
            rep(k, n){
                if(max(H - abs(i - x[k]) - abs(j - y[k]), z) != h[k])  flg = 0;
            }
            if(flg && H){
                cout << i << " " << j << " " << H << endl;
                return;
            }
        }
    }	

}	

int main(){
    
    fastio;
	solve();
    
	return 0;
	
}
