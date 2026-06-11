// VU TRUONG AN
#include <bits/stdc++.h>
#define F first
#define S second
#define maxn 200005
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define pi acos(-1)
#define bit(p,x) ((x>>p) & 1)
#define Task "CF"
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int > piii;

const int base = 200003;
const long long MM = 1ll * MOD * MOD;

int n,k;
void Solve(){
    cin >> n >> k;
    ll ans = 0;
    int a = k;
    for(int b = k + 1;b <= n;++b){
        while(a <= n){
            if(a == 0) -- ans;
            if(a + b <= n) ans += b - k;
            else ans += min(b - k,n - a + 1);
            a += b;
        }
        a = k;
    }
    cout << ans;
}

void NumTime(){cerr << "Toi" << "\n";cerr << "Di" << "\n";cerr << "Chep" << "\n";cerr << "Code" << "\n";}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
#endif
    int test = 1;
//    cin >> test;
    while(test--){
        NumTime();
        Solve();
    }
}
