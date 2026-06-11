#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;

int32_t main(){
   fast;
   int n;
   cin >> n;
   map<char , int>m;
   int ans = 0;
   string t = "MARCH";
   f(i,0,n){
      string s;
      cin >> s;
      if(t.find(s[0]) == -1) continue;
      f(j,0,5) if(t[j] != s[0]) f(k,j+1,5) if(t[k] != s[0]) ans += m[t[j]] * m[t[k]];

      m[s[0]]++;
   }

   cout << ans << "\n";
}