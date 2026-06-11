#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back

typedef long long LL;
typedef  pair<int,int > PII;

const double PI = acos(-1.0);
//const int INF = 1000 * 1000 * 1000 + 1;
const LL INF = 1e15 + 7;
const int MAS =4e5; //5;
const int MOD = 998244353;
const double EPS = 1e-8;


typedef vector<int > VI;
typedef vector<LL> VL;





struct str  {
    int sol ,val, vag;
};
bool cmp (str a , str b)
{
  return a.vag + a.sol < b.vag + b.sol ;
}
int main() {
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    IOS;
     int n;
     cin >> n;
     vector<str> el(n);
     rep(i,n)
     {
         cin >> el[i].vag >> el[i].sol >> el[i].val  ;
     }
     sort(ALL(el),cmp);
  //   reverse(ALL(cmp));
    
     vector<LL > dp ( MAS);
     int mx = 20100 ;
     rep(i,n)
     {
         for(int w= min (el[i].sol , mx - el[i].vag);w >=0 ; w--)
         {
             dp[w  + el[i].vag] = max(dp[w+el[i].vag] ,dp[w]+el[i].val)  ;
         }

     }
     LL ans = 0;
     rep(i,20100)
     {
         ans =max(ans,dp[i]);
     }
     cout << ans << endl;

}