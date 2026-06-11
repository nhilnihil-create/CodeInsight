#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 9223372036ll;
const int nax = 55;
int n,k,ans = 0;
int v[nax];
int check(vector<int> s,int left)
 {
  //cerr<<left<<" ";
  int sum = 0;
  sort(s.begin(), s.end());
  for(auto x: s){
    //cerr<<x<<" ";
    if(x<0 && left>0)
       left--;
    else
       sum += x;
  }
 //cerr<<sum<<END;
 return sum;
 }
void solve()
 {
  cin>>n>>k;
  loop(i,1,n+1)
   cin>>v[i];
  vector<int> s;
  for(int i=0; i<=min(n,k); i++)
     {
      if(i!=0)
       s.pb(v[i]);
      int left = k-i;
      vector<int> now = s;
      int temp = left;
      for(int j=n+1; j>=i+1; j--)
         {
          if(j!=n+1){
            now.pb(v[j]);
            temp--;
          }
          if(temp>=0)
            ans = max(ans,check(now,temp));
          else
             break;
         }
     }
  cout<<ans;
 }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 

     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 