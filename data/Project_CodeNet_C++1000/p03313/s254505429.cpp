#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;


unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 3001;

vi A;

vi solve(vi & B){
    if(sz(B) == 1)return {B[0]};
    vi B1,B2;
    vi ANS;
    rep(c1,0,sz(B)/2){
        B1.push_back(B[c1]);
        B2.push_back(max(B[c1], B[c1+sz(B)/2]));
    }
    vi A1,A2;
    A1 = solve(B1);
    A2 = solve(B2);
    int ma = 0;
    rep(c1,0,sz(B)/2){
        ANS.push_back(A1[c1]);
        ma = max(ma, A1[c1]);
    }
    rep(c1,0,sz(B)/2){
        ANS.push_back(max(max(ma,A2[c1]), B[c1] + B[c1+sz(B)/2]));
        ma = max(ma, ANS[c1+sz(B)/2]);
    }
    return ANS;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    rep(c1,0,1<<n){
        cin >> a;
        A.push_back(a);
    }
    vi ANS = solve(A);
    rep(c1,1,1<<n){
        cout << ANS[c1] << "\n";
    }

    return 0;
}
