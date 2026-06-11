#include<bits/stdc++.h>                                                                                               
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
#define mk_p(a,b)   make_pair((a),(b))
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    string s;
    cin >> s;
    int n = s.size(),cnt = 0;
    rep(i,n){
        if(s[i] == 'x') cnt++;
    }   
    if(15 - cnt >= 8) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
