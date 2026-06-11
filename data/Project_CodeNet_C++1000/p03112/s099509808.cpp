#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s(a+2);
    vector<ll> t(b+2);
    s[0]=-1e11;
    t[0]=-1e11;
    for(int i = 0; i < a; i++) {
        cin >> s[i+1];
    }
    for(int i = 0; i < b; i++) {
        cin >> t[i+1];
    }
    s[a+1]=1e11;
    t[b+1]=1e11;
    for(int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        ll ls,rs,lt,rt;
        auto sit=lower_bound(s.begin(),s.end(),x);
        auto tit=lower_bound(t.begin(),t.end(),x);
        ls= x - *(sit-1);
        rs= *(sit)   - x;
        lt= x - *(tit-1);
        rt= *(tit)   - x;
        ll route[4];
//        cout << ls << " " << rs << " " << lt << " " << rt << "\n";


        route[0]=max(rt,rs);
        route[1]=max(lt,ls);
        route[2]=lt+rs+min(lt,rs);
        route[3]=rt+ls+min(rt,ls);
//        cout << route[0] << " " << route[1] << " " << route[2] << " " << route[3] << "\n";
        cout << min({route[0], route[1], route[2], route[3]}) << "\n";
    }

    return 0;
}