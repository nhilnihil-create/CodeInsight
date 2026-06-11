#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

ll powmod(ll N, ll P){
    if(P<=0) return 1;
    if(P%2==0){
        ll t = powmod(N, P/2);
        return t*t % mod;
    }
    return N*powmod(N, P-1)%mod;
}

int main() {
    string s;
    cin >> s;
    int n=s.length();
    ll dpa[n][4];
    ll dpb[n][4];
    ll dpc[n][4];
    rep(i,n){
        rep(j,4){
            dpa[i][j]=0;
            dpb[i][j]=0;
            dpc[i][j]=0;
        }
    }
    int cnt=0;
    rep(i,n){
        if(i==0){
            if(s[i]=='A')dpa[i][0]++;
            if(s[i]=='?'){
                dpa[i][1]++;
                cnt++;
            }
            continue;
        }
        rep(j,4){
            dpa[i][j]=dpa[i-1][j];
            dpb[i][j]=dpb[i-1][j];
            dpc[i][j]=dpc[i-1][j];
        }
        if(s[i]=='A')dpa[i][0]++;
        if(s[i]=='B')rep(j,2)dpb[i][j]+=dpa[i-1][j];
        if(s[i]=='C')rep(j,3)dpc[i][j]+=dpb[i-1][j];
        if(s[i]=='?'){
            rep(j,3){
                dpa[i][j+1]++;
                dpb[i][j+1]+=dpa[i-1][j];
                dpc[i][j+1]+=dpb[i-1][j];
            }
            cnt++;
        }
        rep(j,4){
            dpa[i][j]%=mod;
            dpb[i][j]%=mod;
            dpc[i][j]%=mod;
        }
    }
    ll sum=0;
    sum+=dpc[n-1][0]*powmod(3,cnt);
    sum%=mod;
    sum+=dpc[n-1][1]*powmod(3,cnt-1);
    sum%=mod;
    sum+=dpc[n-1][2]*powmod(3,cnt-2);
    sum%=mod;
  	sum+=dpc[n-1][3]*powmod(3,cnt-3);
    sum%=mod;
    cout << sum;
}

/*



 */

