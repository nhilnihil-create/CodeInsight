#include <bits/stdc++.h>
#define MAXN 10010
#define pii pair<int, int>
#define pb push_back
#define mt make_tuple
typedef long long ll;

using namespace std;

int n;
ll dp[1010][30100];
vector<tuple<ll, ll, ll> > a;

bool sumsort(const tuple<ll, ll, ll>& a, const tuple<ll, ll, ll>& b){ 
    return (get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b)); 
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        ll w, s, v;
    	cin >> w >> s >> v;
        a.pb(mt(w, s, v));
    }
    sort(a.begin(), a.end(), sumsort);
    for(int i = 0; i < n; i++){
        ll w, s, v;
        tie(w, s, v) = a[i];
        for(int j = 0; j <= 30000; j++){
            if(i == 0){
                if(j >= w) dp[i][j] = v;
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            if(j < w) continue;
            dp[i][j] = max(dp[i][j], v + dp[i - 1][min(s, j - w)]);
        }
    }
    cout << dp[n - 1][30000];
}