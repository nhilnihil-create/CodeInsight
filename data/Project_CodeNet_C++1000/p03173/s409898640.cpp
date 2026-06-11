#include <bits/stdc++.h>
using namespace std;

//Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//save time
#define endl '\n'
#define db(x) cerr << "> " << #x << ": " << x << endl
typedef long long ll;

//for sorting
#define all(a) a.begin(),a.end()

//Constants
#define PI   3.141592653593
#define MOD  1000000007LL
#define EPS  0.000000001
#define INF  0X3f3f3f3f

//loops
#define REP(i,n)      for(int i=0;i<(n);++i)
#define FOR(i,a,b)      for(int i=(a);i<(b);++i)
#define DFOR(i,a,b)     for(int i=(a);i>=(b);--i)

//vectors
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pair<int,int>>
#define vlll vector<pair<ll,ll>>
#define pb  push_back
#define vb vector<bool>

//pairs
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second

//fast I/O
#ifndef _WIN32
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
#define gc getchar
#define pc putchar

//If using cin and cout
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(NULL);cout.tie(NULL)

//queue
#define di deque<int>
#define dll deque<ll>
#define qi queue<int>
#define PQ priority_queue

//general
#define E empty()

const int MAXN=405;
vector<vll> dp(MAXN, vll(MAXN, 0));


int main(){
    int n ;cin >> n ;
    vi ar(n);
    REP(i,n)
        cin>>ar[i];
    auto cost = [&ar](int l, int r){
        ll res = 0;
        FOR(i, l, r+1){
           res+=ar[i];
        }
        return res;
    };
    for(int l = n-1; l >=0; --l){
        for(int r = l; r <  n; ++r){
            if(r == l)
                dp[l][r]=0;
            else{
                dp[l][r]=LONG_MAX;
                ll c = cost(l, r);
                for(int k = l ; k < r; ++k){
                    dp[l][r]=min(dp[l][r], dp[l][k]+dp[k+1][r]+c);
                }
                // dp[l][r] = min(dp[l][r], dp[l])
            }
        }
    }
    cout << dp[0][n-1] << endl;

}
