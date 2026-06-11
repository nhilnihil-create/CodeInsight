#include <bits/stdc++.h>
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

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


string s = "z";
vector<char> t(200010),d(200010);
map<char,ll> dir;
bool simu(bool left, ll index){
    ll temp = index;
    bool test = false;
    /*if(index == 6 || index == 7){
        cout<<index<<endl;
        test = true;
    }*/
    rep(i,Q){
        if(t[i] == s[temp]) temp += dir[d[i]];
        if(left && (temp == 0)) return true;
        if(!left && (temp == N+1)) return true;
        if(test) cout<<i<<' '<<temp<<endl;
    }
    return false;
}
int main() {
    cin>>N>>Q>>S;
    s.append(S);
    s.append("z");
    //rep(i,s.size())cout<<s[i];
    //cout<<endl;
    rep(i,Q) cin>>t[i]>>d[i];
    dir['L'] = -1;
    dir['R'] = 1;
    ll left,right;
    ll lb = 0, ub = N+2;
    while(ub - lb > 1){
        ll cen = (ub + lb) / 2;
        (simu(true,cen) ? lb : ub) = cen;
    }
    left = lb;
    lb = N+1; ub = -1;
    while(lb - ub > 1){
        ll cen = (ub + lb) / 2;
        (simu(false,cen) ? lb : ub) = cen;
    }
    right = lb;
    cout<<max(0LL, right - left - 1)<<endl;
    //cout<<left << ' '<<right<<endl;
    //cout<<dir['L']<<' '<<dir['R']<<endl;
}
