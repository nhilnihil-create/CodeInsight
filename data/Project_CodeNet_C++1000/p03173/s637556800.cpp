#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define MOD 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define M 1e6+9
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

ll n,k,a,b,c,d,x,y,z,m,l;
ll ans;
vecl arr(N);
ll dp[509][509];
ll pre[N];





void test_case() {

    ll n;
    cin>>n;


    vecl arr(n);
    rep(i,n) {
        cin>>arr[i];
    }

    vecl pre_sum(n+1, 0);

    for(int i=1; i<=n; i++) {
        pre_sum[i] = pre_sum[i-1] + arr[i-1];
    }

    for(int l=n-1; l>=0; l--) {
        for(int r =l; r<n; r++) {
            if(l==r) {
                dp[l][l] = 0;
            } else {
                dp[l][r] = LONG_MAX;
                ll sum = pre_sum[r+1] - pre_sum[l];
                // cout<<sum<<endl;
                for(int i=l; i<=r; i++) {
                    dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r] + sum);
                }
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    // }


    cout<<dp[0][n-1]<<endl;




}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
    // cin >> t;
    while(t--)
    {   
        test_case();
    }
}
