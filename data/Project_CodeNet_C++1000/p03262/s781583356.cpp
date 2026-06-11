#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, n){
        cin >> a[i];
        a[i] -= x;
    }

    int g = abs(a[0]);
    rep(i, n) g = __gcd(g, abs(a[i]));
    
    cout << g << endl;
}