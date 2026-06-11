#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
const ll MOD = 1e9+7;

#define pll pair<ll,ll>

ll dp1[51][51];
ll dp2[51][51];
ll v[51];
priority_queue<ll,vector<ll>,greater<ll>> pq;


int main(){
    int N,K; cin>>N>>K;
    for(int i=1;i<=N;++i){
        cin >> v[i];
    }
    
    dp1[0][0] = 0;    
    for(int i=1;i<=N;++i){
        dp1[i][0] = dp1[i-1][0]+v[i];
        for(int j=1;j<=i;++j){
            pq.push(v[j]);
        }
        
        for(int j=1;j<=i;++j){
            dp1[i][j] = dp1[i][j-1] - pq.top();
            pq.pop();
        }
    }
    
    
    dp2[0][0] = 0;
    for(int i=1;i<=N;++i){
        dp2[i][0] = dp2[i-1][0]+v[N-i+1];
        for(int j=1;j<=i;++j){
            pq.push(v[N-j+1]);
        }
        
        for(int j=1;j<=i;++j){
            dp2[i][j] = dp2[i][j-1] - pq.top();
            pq.pop();
        }
    }
    
    ll ans = 0;
    for(int Lget=0;Lget<=K;++Lget){
        for(int Rget=0;Rget<=K;++Rget){
            if(Lget+Rget>N){ break;}
            
            for(int Lth=0;Lth<=Lget;Lth++){
                for(int Rth=0;Rth<=Rget;++Rth){
                    if(Lget+Rget+Lth+Rth>K){break;}
                    chmax(ans, dp1[Rget][Rth] + dp2[Lget][Lth]  );
                }
            }
        }
    }
    
    

    cout << ans << "\n";
}
