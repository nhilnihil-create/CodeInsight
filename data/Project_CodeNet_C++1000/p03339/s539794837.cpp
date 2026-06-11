#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define rreps(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    int n; string s;
    cin >> n >> s;
    
    vector<int> W(n+2,0), E(n+2,0);
    reps(i,1,n){
        W[i] = W[i-1];
        if(s[i-1]=='W') W[i]++;
    }
    rreps(i,n,1){
        E[i] = E[i+1];
        if(s[i-1]=='E') E[i]++;
    }
    
    int ans = INT_MAX;
    reps(i,1,n){
        ans = min(ans, W[i-1] + E[i+1]);
    }
    
    cout << ans << endl;
}