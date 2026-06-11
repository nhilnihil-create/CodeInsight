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
const int inf = 92233720ll;
bool mywish(const pair<pair<string,int>,int> &a,const pair<pair<string,int>,int> &b)
  {
    if(a.ff.ff == b.ff.ff)
       return a.ff.ss > b.ff.ss;
    else
       return a.ff.ff < b.ff.ff;
  }
  
void solve()
 { 
  int n;
  cin>>n;
  vector<pair<pair<string,int>,int>> v(n);
  loop(i,0,n)
   {
    string s;
    int p;
    cin>>s>>p;
    v[i] = {{s,p},i+1};
   }
  sort(v.begin(), v.end(),mywish);
  loop(i,0,n)
   cout<<v[i].ss<<END;
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