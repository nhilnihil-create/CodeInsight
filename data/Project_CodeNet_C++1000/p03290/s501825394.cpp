// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"

const ll MOD = 1000000007;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    int d, g;
    cin >> d >> g;
    int p[20], c[20];
    rep(i, 0, d) cin >> p[i] >> c[i];
    rep(i, 0, d) c[i] /= 100; g /= 100;

    int res = 1e9;

    repp(x, 0, 2047){
        int cnt = 0, sum = 0;
        vector<bool> mark(10, 1);
        rep(i, 0, d){
            if((x >> i) & 1){
                cnt += p[i];
                mark[i] = 0;
                sum += (i + 1) * p[i] + c[i];
            }
        }
        priority_queue<int> q;
        rep(i, 0, d) if(mark[i]) rep(j, 0, p[i]) q.push(i + 1);
        while(sum < g && !q.empty()){
            sum += q.top();
            q.pop();
            cnt++;
        }
        res = min(res, cnt);
    }

    cout << res;
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}