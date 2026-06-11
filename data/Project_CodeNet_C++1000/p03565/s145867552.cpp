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
  int tt;
  tt = 1;
  // cin>>tt;
  while(tt--){
    string s,t;
    cin>>s>>t;
    string ans = "~";
    int n = s.size();
    int m = t.size();
    rep(i,0,n - m){
      string s2 = s;
      bool ok = true;
      rep(j,0,m-1){
        if(s[i+j]==t[j] || s[i+j]=='?'){
          s2[i+j] = t[j];
        }
        else{
          ok = false;
          false;
        }
      }
      if(ok){
        replace(s2.begin(), s2.end(), '?', 'a');
        ans = min(ans, s2);
      }
    }

    if(ans == "~"){
      cout<<"UNRESTORABLE"<<nl;
    }
    else{
      cout<<ans<<nl;
    }
  }
  return 0;
}
