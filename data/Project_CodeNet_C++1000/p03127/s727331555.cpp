/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
long long dp[100005];;

long long gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}


int main(){

 int n,x; cin>>n;
 vector<int>v(n);

 cin>>v[0];
 long long g = v[0];

 for(int i=1;i<n;i++){
    cin>>v[i];
     g = gcd(g,v[i]);
 }

 cout<<g<<endl;

return 0;
}