#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll>East(n+1,0);
    vector<ll>West(n+1,0);
    for (int i=1; i<=n; i++){ //累積和を格納
        if (s[i-1] == 'E'){
            East[i] = East[i-1]+1;
            West[i] = West[i-1];
        }
        else{
            East[i] = East[i-1];
            West[i] = West[i-1]+1;
        }
    }
    // rep(i,n+1) cout << East[i] << ", " << West[i] << endl;
    ll ans = LLINF;
    for (int i=1; i<=n; i++){ //i番目の人がリーダー
        ll left_to_right = West[i-1];
        ll right_to_left = East[n] - East[i];
        ans = min(ans, left_to_right+right_to_left);
    }
    cout << ans << endl;
}