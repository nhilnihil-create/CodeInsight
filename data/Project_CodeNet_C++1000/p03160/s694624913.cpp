#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a; i<=b; i++)
#define ll long long int
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
const int mod = 1000000007;
//=======================

int arr[100005], n;
int dp[100005];

int frog(int i)
{
    if(i == n-1)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int left = abs(arr[i] - arr[i+1]) + frog(i+1);

    int right = INT_MAX;
    // taking right first as INT_MAX so that it won't affect the minimum value 
    // when we return the min of (left, right);
    // checking the condition so that i don't go out of bound.

    if(i+2 < n)
    {
         right = abs(arr[i] - arr[i + 2]) + frog(i+2);
    }

    return dp[i] = min(left, right); 
}
void solve() {
     cin>>n;

     memset(dp, -1 , sizeof(dp));

     rep(i, 0, n)
     cin>>arr[i];

     cout<<frog(0)<<endl;


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    solve();

    return 0;
}
