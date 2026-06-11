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

int n,m;
void Solve(){
    cin >> n >> m;
    if(n > m) swap(n,m);
    if(n == 1 && m == 1) cout << 1;
    if(n == 1 && m > 1) cout << m - 2;
    if(n >= 2 && m >= 2) cout << 1ll * (n - 2) * (m - 2);
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
