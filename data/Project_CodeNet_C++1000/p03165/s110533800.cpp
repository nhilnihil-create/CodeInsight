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
const ll linf = 1e18L +5;
const int inf = 1e9 +5 ;

int main(){
   // InputOuput;
    Fast;
    string a,b ; cin >> a >> b ;
    int n = a.size(), m = b.size();

    if(n<m){
        swap(a,b);
        swap(n,m);
    }


    vvi dp(m+1, vi(n+1, 0));

    for1(i,m){
        //vector<int> np(n+1,0);
        for1(j,n){
            if(a[j-1] == b[i-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                //ans.pb(a[j-1]);
            }
            else{

                dp[i][j] = max(dp[i][j-1], dp[i-1][j]) ;

            }
        }

    }
    //cout << dp[m][n]<<'\n';
    int si = dp[m][n];
    int i =m , j = n ;
    string ans( si,' ');
    si--;
    while(i> 0 && j>0){
        if(a[j-1] == b[i-1]){
            ans[si] = a[j-1];
            j--;
            i--;
            si--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    cout << ans <<'\n';
    return 0;

}