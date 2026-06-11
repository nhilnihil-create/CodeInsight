#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define forn(i,a,b) for (int i = a; i <= b; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
#define er erase
#define in insert
#define pi pair <int, int>
# define sz(x) (int)((x).size())
#define int long long

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 0x3f3f3f3f3f3f3f;
const ll mod = 1000000007;
const int N = 2e6 + 11;
const int W = 1e4 + 11;
const long long INF64 = 3e18 + 1;


int n;

struct yes{
    int w,s,v;
};

bool cmp(yes x,yes y){
    return (x.s + x.w < y.s + y.w);
}

yes a[N];

int dp[N];

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].w >> a[i].s >> a[i].v;
    }

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        for(int j = a[i].s + a[i].w; j >= a[i].w; j--){
            dp[j] = max(dp[j] , dp[j - a[i].w] + a[i].v);
        }
    }

    int ans = 0;

    for(int i = 1; i <= 2e6; i++)ans = max(ans , dp[i]);

    rc(ans);

}
