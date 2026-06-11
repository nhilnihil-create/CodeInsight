#include <bits/stdc++.h>  // This will work only for g++ compiler.
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forab(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define pb push_back
#define fi first
#define se second
#define __builtin_popcount(x) ones(x)
#define __builtin_popcountl(x) onesl(x)
#define __builtin_popcountll(x) onesll(x)// to be used with algorithms that processes a container Eg: find(all(c
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define InputOuput freopen("input.txt", "r", stdin); freopen("output.txt","w", stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
ll inf = 1e9 +5;
int main(){
    //InputOuput;
    Fast;

    int n, k ; cin >> n >>k;
    int last = 1;
    vll h(n+1);
    for1(i,n) cin >> h[i];
    vll dp(n+1,inf);
    dp[1] = 0;
    for1(i,n){
        forab(j,i+1, i+k){
            if(j<=n){
                dp[j] = min(dp[i] + (ll)abs(h[i]-h[j]) , dp[j]);
            }
        }
    }
    cout << dp[n]<<'\n';
    return 0;

}