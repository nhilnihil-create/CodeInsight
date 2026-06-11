#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
// debug templates 
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";
 
const int mxN = 55;
// dp[i][j] -> i operations A's and j operation B's
multiset<ll> dp[mxN][mxN];
// first take the jewels out, and then in the end we put the negative valued jewels back
void solve(){
    int n,cnt; cin >> n >> cnt;
    ll a[n],b[n];
    FOR(n){
        cin >> a[i];
        b[i] = a[i];
    }
    reverse(b,b+n);

    FOR(i,n+1){
        FOR(j,n+1){
            if(i+j < n){
                FOR(k,i) dp[i][j].insert(a[k]);
                FOR(k,j) dp[i][j].insert(b[k]);
            } else{
               FOR(k,n) dp[i][j].insert(a[k]); 
            }
        }   
    }

    ll ans = 0;
    FOR(i,n+1){
        FOR(j,n+1){
            if(i+j > min(cnt,n)) continue;
            int operations_left = cnt - (i+j);
            while(operations_left){
                if(dp[i][j].empty()) break;
                auto itr = dp[i][j].begin();
                if(*itr < 0) dp[i][j].erase(itr);
                else break;
                --operations_left;
            }
            ll temp_ans = 0;
            for(ll v : dp[i][j]) temp_ans += v;
            ans = max(ans,temp_ans);
        }
    }
    cout << ans;

}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	return 0;
}
 
