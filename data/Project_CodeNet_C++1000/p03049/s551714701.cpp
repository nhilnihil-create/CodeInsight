#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define For(i, s, e) for(int i = s;i <= e;i++)
#define Sort(v, n) sort(v, v+n);
#define VSort(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define cY cout<<"Yes";
#define cN cout<<"No";
#define cA(a) cout<<a;
const ll MOD = 1000000007;



int main() {
    ll n,ans = 0,A = 0,B = 0, AB = 0;
    cin >> n;
    string s;
    rep(i,n) {
        cin >> s;
        rep(j,s.size()-1) {
            if(s[j] == 'A' && s[j+1] == 'B') ans++;
        }
        if(s[0] == 'B' && s[s.size() -1] == 'A') {
            AB++;
        } else if(s[0] == 'B') {
            B++;
        } else if(s[s.size()-1] == 'A') {
            A++;
        }
    }
    if(AB == 0) {
        ans += min(A,B);
    } else if (A+B == 0){
        ans += AB-1;
    } else {
        ans += min(A+AB,B+AB);
    }
    cout << ans;
}
