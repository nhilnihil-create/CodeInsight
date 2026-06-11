#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    
    if(s[0] == '0' || s[n-1] == '1'){
        printf("-1\n");
        return 0;
    }
    
    vector<pii> ans;
    int t = n-1;
    rrep(i, n-1){
        if(s[i] != s[n-2-i]){
            printf("-1\n");
            return 0;
        }
        
        ans.push_back(pii(t+1, i+1));
        if(s[i] == '1') t = i;
    }
    
    for(pii p: ans) printf("%d %d\n", p.fi, p.se);
}