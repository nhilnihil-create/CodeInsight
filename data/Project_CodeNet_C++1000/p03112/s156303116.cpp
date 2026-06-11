#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n,m) for(int (i)=(n);(i)<(m);(i)++)
#define rrep(i,n,m) for(int (i)=(n);(i)>(m);(i)--)
using ll = long long;
const ll MOD = 1e9+7;
 
int main(){
 
    int A,B,Q;
    cin >> A >> B >> Q;
 
    vector<ll> s(A+2,0);
    vector<ll> t(B+2,0);
 
    s[0] = -30000000001;
    t[0] = -30000000001;
    s[A+1] = 30000000000;
    t[B+1] = 30000000000;
 
    rep(i,0,A){
        cin >> s[i+1];
    }
    rep(i,0,B){
        cin >> t[i+1];
    }
 
    ll x;
    int si,ti;
    ll ls,lt,rs,rt;
    rep(loop,0,Q){
 
        cin >> x;
        si = distance(s.begin(),lower_bound(s.begin(),s.end(),x));
        ti = distance(t.begin(),lower_bound(t.begin(),t.end(),x));
        ls = x - s[si-1];
        lt = x - t[ti-1];
        rs = s[si]-x;
        rt = t[ti]-x;
 
        cout << min({ max(ls,lt) , max(rs,rt) , min(ls,rt) * 2 + max(ls,rt) , min(lt,rs) * 2 + max(lt,rs) }) << endl;
    }
 
}