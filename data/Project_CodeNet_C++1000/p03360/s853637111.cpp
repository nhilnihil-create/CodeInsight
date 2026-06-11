#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  ll ans;
  if(a>=b && a>=c)ans=b+c+a*pow(2,k);
   else if(c>=b && c>=a)ans=b+a+c*pow(2,k);
   else if(b>=a && b>=c)ans=c+a+b*pow(2,k);
  cout << ans << endl;
}
  
      
    
