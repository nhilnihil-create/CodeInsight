#include <bits/stdc++.h>
#include <bitset>
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

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N;
    vec d(N);
    rep(i,N) cin>>d[i];
    vec ott(12,0);
    rep(i,N){
        if(d[i] == 0){
            cout<<0<<endl;
            return 0;
        }else if(d[i] == 12 && N== 1){ 
          cout<<12<<endl; 
          return 0; 
        }else {
            --d[i];
            ++ott[d[i]];
            if(ott[d[i]] + (d[i] / 11) == 3){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    ll ans = 0;
    rep(s, (1<<12)){
        ll temp = 12, last = -1;
        rep(i, 12){
            if(((ott[i] == 1) && (s>>i)&1) || (ott[i] + (i/11) == 2)){
                temp = min(temp, i - last);
                last = i;
            }
        }
        Rrep(i,11){
            if(((ott[i] == 1) && ((s>>i)^1)&1) || (ott[i] == 2)){
                temp = min(temp, 22 - i - last);
                last = 22 - i;
            }
        }
      temp = min(temp, 23 - last);
        ans = max(ans, temp);
    }
    cout<<ans<<endl;
}
