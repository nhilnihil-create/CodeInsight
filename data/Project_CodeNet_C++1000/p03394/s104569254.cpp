#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    cin>>N;
    if(N == 3){
        cout<<2<<' '<<5<<' '<<63<<endl;
    }else if(N <= 24){
        vec ans = {2,3,4,9};
        rep(i, N - 4) ans.push_back((i+1)*6);
        rep(i, ans.size()){
            cout<<ans[i];
            i == ans.size() - 1 ? cout<<endl : cout<<' ';
        }
    }else{
        ll num_6 = min(2500LL, N/6);
        vec ans(0);
        rep(i, num_6 * 2) rep(j, 3) ans.push_back(i*6 + j + 2);
        ll rest = N - ans.size();
        rep(i, rest) ans.push_back((i+1) * 6);
        rep(i, ans.size()){
            cout<<ans[i];
            i == ans.size() - 1 ? cout<<endl : cout<<' ';
        }
    }
}
