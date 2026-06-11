#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,ll>;
const ll inf=1000000000007;
const int mod=1000000007;


int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
};


int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  int val=a[0];
  rep(i,1,n){
    val=gcd(val,a[i]);
  }
  cout << val << endl;
  return 0;

}
