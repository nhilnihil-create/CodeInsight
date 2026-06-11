#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  rep(i,q){
      int k;
      cin >> k;
      ll a=0,m=0,l=0,ans=0;
      rep(i,n){
          if (s[i]=='D') a++;
          if (s[i]=='M'){
              m++;
              l+=a;
          }
          if (s[i]=='C') ans+=l;
          if (i+1-k>=0){
              if (s[i+1-k]=='D'){
                  a--;
                  l-=m;
              }
              if (s[i+1-k]=='M'){
                  m--;
              }
          }
      }
      cout << ans << endl;
  }
}
