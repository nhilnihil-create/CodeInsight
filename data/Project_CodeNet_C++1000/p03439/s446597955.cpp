#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    cout << 0 << endl;
    string S; cin >> S;
    if (S=="Vacant") return 0;
    int lb=0,ub=N,pre=0,seat=(S=="Male"?0:1);
    while(1){
        int mid=(lb+ub)>>1;
        cout << mid << endl;
        cin >> S;
        if (S=="Vacant") return 0;
        int now=(S=="Male"?0:1);
        if (pre<mid) ((mid-pre)%2==abs(now-seat)%2?lb:ub)=mid;
        else ((pre-mid)%2==abs(seat-now)%2?ub:lb)=mid;
    }
}