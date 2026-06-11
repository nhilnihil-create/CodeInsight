#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 5e5 + 10;

ll n;int ans = 0;
void judge(int v){
    int a = 0;int b = 0;int c = 0;
    while(v%10){
        int u = v%10;
        v /=10;
        if(u==3)a++;
        else if(u==5)b++;
        else if(u==7)c++;
    }
    if(a>0&&b>0&&c>0) ans++;
}

void dfs(ll v){
   if(v>n) return;
   judge(v);
   dfs(v*10+3);
   dfs(v*10+5);
   dfs(v*10+7);
}

void solve(){
    cin >> n;
    dfs(0);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}