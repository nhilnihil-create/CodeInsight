#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define mod 1000000007
typedef long long ll;
using namespace std;



int main(){
    ll A,B,Q;
    ll s[100100],t[100100];
    cin >> A >> B >> Q;
    for(int i=1;i<=A;i++) cin >> s[i];
    for(int i=1;i<=B;i++) cin >> t[i];
    s[0] = -100100100100100100;
    t[0] = -100100100100100100;
    s[A+1] = 100100100100100100;
    t[B+1] = 100100100100100100;
    for(int i=0;i<Q;i++){
        ll x;
        cin >> x;
        int itr_s = upper_bound(s,s+A+2,x) - s;
        int itr_t = upper_bound(t,t+B+2,x) - t;

        ll ans = 100100100100100100;
        ll shrine[2] = {s[itr_s-1], s[itr_s]};
        ll temple[2] = {t[itr_t-1], t[itr_t]};

        // shrine -> temple
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ll d = abs(x - shrine[i]) + abs(shrine[i] - temple[j]);
                ans = min(ans, d);
            }
        }

        // temple -> shrine
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ll d = abs(x - temple[i]) + abs(temple[i] - shrine[j]);
                ans = min(ans, d);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}