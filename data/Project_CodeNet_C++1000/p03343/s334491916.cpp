#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 59;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main(){
    cin>>N>>K>>Q;
    vec a(N), ord(N), sta(N);
    rep(i,N) cin>>a[i];
    rep(i,N) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](ll x, ll y){
        return a[x] < a[y];
    });
    set<ll> ID = {-1};
    ID.insert(N);

    vec range(0);
    mat r_id(2010,vec(2010));
    ll range_id = -1, ans = INF, last;
    rep(i,N){ //sort順にとる
        auto ite = ID.begin();
        last = *ite;
        ++ite;
        range.push_back(*ite - last - 1);
        ++range_id;
        rep(j,N){
            if(j == *ite){
                last = *ite;
                ++ite;
                range.push_back(*ite - last - 1);
                ++range_id;
            }else{
                r_id[i][j] = range_id;
            }
        }
        ll q = Q, temp, mini;
        reps(j,i,N){
            if(range[r_id[i][ord[j]]] >= K){
                if(q == Q) mini = a[ord[j]];
                temp = a[ord[j]];
                --range[r_id[i][ord[j]]];
                --q;
            }
            if(q == 0) break;
        }
        if(q == 0) {
            //cout<<i<<' '<<temp<<' '<<mini<<endl;
            ans = min(ans, temp - mini);
        }
        ID.insert(ord[i]);
        while(i + 1 < N){
            if(a[ord[i]] != a[ord[i+1]]) break;
            ID.insert(ord[i]);
            ++i;
        }
    }
    cout<<ans<<endl;
}