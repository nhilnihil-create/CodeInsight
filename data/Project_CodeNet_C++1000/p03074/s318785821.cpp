#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
using pi = pair<int,int>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

signed main(){
	//cout << fixed << setprecision(10);
    int n,k; cin >> n >> k;
	string s; cin >> s;
    vector<pi> vec(0);
    int f = (s[0] == '0' ? 1 : 0);
    int cnt = 0;
    rep(i,0,n){
        int g = (s[i] == '0' ? 1 : 0);
        if(f != g){
            vec.push_back(make_pair(cnt , f));
            f = g;
            cnt = 0;
        }
        cnt++;
    }
    if(cnt != 0)vec.push_back(make_pair(cnt , f));
    int ans = 0;
    int memo = 0;
    int ind = 0;
    cnt = 0;
    if(vec.size() == 1){
        cout << n << endl;
        return 0;
    }
    rep(i,0,vec.size()){
        cnt += vec[i].second;
        while(cnt > k){
            cnt -= vec[ind].second;
            memo -= vec[ind].first;
            ind++;
        }
        memo += vec[i].first;
        chmax(ans , memo);
    }
    chmax(ans , memo);
    cout << ans << endl;

	return 0;
}