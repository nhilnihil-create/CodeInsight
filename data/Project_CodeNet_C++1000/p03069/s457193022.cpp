#include <bits/stdc++.h>
#define Rep(i,j,n) for(int i=j; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;
 
int main(){
  int n; cin >> n;
  string s; cin >> s;
  int w=0;

  rep(i,n){
    if(s[i]=='.') w++;
  }

  int b=0;
  int ans=INF;

  rep(i,n){
    ans=min(ans,w+b);
    if(s[i]=='.') w--;
    else b++;
  }
  ans=min(ans,w+b);
  
  cout << ans << endl;
  return 0;
}
