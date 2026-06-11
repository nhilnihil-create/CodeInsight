#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> ;
#define pal pair < ll, ll> ;
#define vi vector <int> ;
#define vl vector < ll > ;
#define vpai vector < pii > ;

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 100045;

int dp[sze];

int solve(int k,int n,int arr[]) {
    if(dp[k]) return dp[k];

    rep(i,n){
        if(k>=arr[i]){
            if(solve(k-arr[i],n,arr)==2){
                dp[k]=1;
                return dp[k];
            }
        }
    }
    dp[k]=2;
    return dp[k];
}   

int main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        int arr[n];
        dp[0]=2;
        rep(i,n) cin>>arr[i];
        if (solve(k,n,arr)==1)
        {
            cout<<"First";   
        }else cout<<"Second";
    }

  return 0;
}