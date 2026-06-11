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
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}


int main(){

 ll n,m;
 cin>>n>>m;

  ll a[n],b[m],c[m];
 for(int i=0;i<n;i++)
    cin>>a[i];

 for(int i=0;i<m;i++) cin>>b[i]>>c[i];

 priority_queue< pair<int,int> >Q;

   for(int i=0;i<n;i++)
    Q.push(make_pair(a[i],1));

  for(int j=0;j<m;j++)
    Q.push(make_pair(c[j],b[j]));

  ll ans =0;

  for(int i=0;i<n;i++){

      pair<int,int> p;
      p = Q.top();
      Q.pop();

      ans += p.first;
     if(p.second > 1){
        p.second--;
        Q.push(p); }
  }

  cout<<ans<<endl;

return 0;
}