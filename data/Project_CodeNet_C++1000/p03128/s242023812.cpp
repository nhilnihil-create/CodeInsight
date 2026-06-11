#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;

const int INF = 2000000000;


int main()
{
    int n,m;
    cin >> n >> m;
    ve<int> a(m);
    in(m,a);
    ve<int> c = {0,2,5,5,4,5,6,3,7,6};
    
    ve<pair<int,int>> b;
    rep(i,m) b.push_back({a[i],c[a[i]]});
    sort(all(b));reverse(all(b));
    
    
    vi dp(n+1,-INF);
    dp[0] = 0;
    rep(i,n+1){
        if(dp[i] == -INF) continue;
        rep(j,m){
            if(i+b[j].se <= n){
                dp[i+b[j].se] = max(dp[i+b[j].se], dp[i]+1);
            }
        }
    }
    //outve(dp);
    
    while (n > 0) {
        rep(i,m){
            if(n < b[i].se) continue;
            if(dp[n-b[i].se] == dp[n]-1){
                cout << b[i].fi;
                n-=b[i].se;
                break;
            }
        }
    }
    cout <<endl;


    return 0;
}
