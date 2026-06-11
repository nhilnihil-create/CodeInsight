#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define int ll
#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 1e14 ;
const ll MOD = 1000000007;

const int N = 404;
int ar[N] , ps[N] , dp[N][N];
int n;

int sum(int l , int r){
    return ps[r] - (l ? ps[l - 1] : 0);
}

signed main(){

#ifndef ONLINE_JUDGE
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    fo(i , n) cin >> ar[i];
    fo(i , n){
       if(i) ps[i] += ps[i - 1];
       ps[i] += ar[i];
    }
    //mcm style dp
    for(int len = 1 ; len <= n ; len++){
        for(int l = 0 , r = l + len - 1 ; r < n ; l++ , r++){
            if(l == r){
                dp[l][r] = 0;
                continue;
            }
            dp[l][r] = oo;
            for(int k = l ; k < r ; k++)
                dp[l][r] = min(dp[l][r] , dp[l][k] + dp[k + 1][r] + sum(l , r)); 
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;

}

