#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> pipii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minpq;
typedef priority_queue<pii> maxpq;
//const double PI = acos(-1);
const int mod =1000000007;

// ----------------------DEBUG TEMPLATE--------------------------
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
// ----------------------DEBUG TEMPLATE--------------------------
#define N 100001
int dp[N][4];
vi a(N),b(N),c(N);

int solve(int day,int prev){
    if(day==0){
        return 0 ;
    }
    int op1=INT_MIN,op2=INT_MIN;
    if(dp[day][prev]>-1){
        return dp[day][prev];
    }
    if(prev==1){
        op1 = b[day] + solve(day-1,2);
        op2 = c[day] + solve(day-1,3);
    }
    if(prev==2){
        op1 = a[day] + solve(day-1,1);
        op2 = c[day] + solve(day-1,3);
    }
    if(prev==3){
        op1 = b[day] + solve(day-1,2);
        op2 = a[day] + solve(day-1,1);
    }
    return dp[day][prev] = max(op1,op2);
}

int sovleBU(int n){
    int t[n+1][4];
    t[1][1] = a[1];
    t[1][2] = b[1];
    t[1][3] = c[1];

    for(int i =2;i <=n;i++){
        t[i][1] = a[i] + max(t[i-1][2],t[i-1][3]);
        t[i][2] = b[i] + max(t[i-1][1],t[i-1][3]);
        t[i][3] = c[i] + max(t[i-1][2],t[i-1][1]);
    }
    return max({t[n][1],t[n][2],t[n][3]});
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    
    Fo(i,1,n+1){
        cin>>a[i]>>b[i]>>c[i];
    }
    // int res=INT_MIN;
    // memset(dp,-1,sizeof(dp));
    // res = max(res,solve(n,1)),
    // memset(dp,-1,sizeof(dp));
    // res = max(res,solve(n,2)),
    // memset(dp,-1,sizeof(dp));
    // res = max(res,solve(n,3)),
    cout<<sovleBU(n)<<endl;
}
    