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

int gcd(int a,int b){return b ? gcd(b,a%b) : a;} 
int lcm(int a,int b){return a/gcd(a,b)*b;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    rep(i,n){
        if(s[i] == '2') ++cnt;
    }   
    cout << cnt << '\n';
    return 0;
}
