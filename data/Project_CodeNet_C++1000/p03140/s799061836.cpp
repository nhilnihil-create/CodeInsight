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
    string a,b,c;
    int n,cnt = 0;
    cin >> n >> a >> b >> c;
    rep(i,n){
        if(a[i] == b[i] && a[i] != c[i]) cnt++;
        else if(a[i] == c[i] && a[i] != b[i]) cnt++;
        else if(b[i] == c[i] && b[i] != a[i]) cnt++;
        else if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i]) cnt += 2;
    }   
    cout << cnt << '\n';
    return 0;
}
