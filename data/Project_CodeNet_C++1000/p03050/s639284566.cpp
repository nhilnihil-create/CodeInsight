#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << nl;
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
const int MAXN = 100005;
ll mod=1000000007;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  // cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll cnt = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            ll x = i, y = n/i;
            if(x > 1)
            if((n%(x - 1))* (x) == n){
              cnt+= (x - 1);
            }
            if(y>1)
            if(x != y){
              if(n%(y - 1)*(y) == n){
                cnt+=(y-1);
              }
            }
        }
    }
    cout<<cnt<<nl;
  }
  return 0;
}
