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
  int a,b,c; cin >> a >> b >> c;
  if((a<=c && c<=b) || (a>=c && c>=b)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
