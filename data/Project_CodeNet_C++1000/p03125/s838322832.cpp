// Author : Nachiket Kanore
// Institute : PICT, Pune

/* It does not matter how slowly you go as long as you do not stop.*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define rep(x,s,e) for(int x=s;x<=(e);x++)
#define repn for(int x=0;x<n;x++)
#define rep1n for(int x=1;x<=n;x++)
#define rep1m for(int y=1;y<=m;y++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define precise(x) cout << fixed << setprecision(x)
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define mp make_pair
#define test int t; cin>>t; while(t--)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;


void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define see(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif

const int inf = 1e18;
const int N = 1005;



int32_t main(){
    FAST;

    int a , b;  cin >> a >> b;
    if(b % a == 0)
        cout << a + b << endl;
    else cout << b - a << endl;

    return 0;
}


