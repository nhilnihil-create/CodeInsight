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
    int a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int e = 0,f=0,g=0,h=0;
    rep(i,4){
        if(a[i] == 1) e++;
        else if(a[i] == 9) f++;
        else if(a[i] == 7) g++;
        else if(a[i] == 4) h++;
    }   
    if(e == 1 && f == 1 && g == 1 && h == 1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
