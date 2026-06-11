#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,n;
    cin>>h>>w>>n;
    ll y,x;
    string s,t;
    cin>>x>>y>>s>>t;
    ll L = 0, R = w + 1, U = 0, D = h + 1;
    for(int i = n - 1; i >= 0; i--) {
        if(t[i] == 'L' && R <= w) R++;
        if(t[i] == 'R' && 1 <= L) L--;
        if(t[i] == 'U' && D <= h) D++;
        if(t[i] == 'D' && 1 <= U) U--;
        if(s[i] == 'L') L++;
        if(s[i] == 'R') R--;
        if(s[i] == 'U') U++;
        if(s[i] == 'D') D--;
        if(w <= L || R <= 1 || h <= U || D <= 1) {
            cout << "NO\n";
            return 0;
        }
    }
 
    cout << (L < y && y < R && U < x && x < D ? "YES\n" : "NO\n");

    return 0;
}
