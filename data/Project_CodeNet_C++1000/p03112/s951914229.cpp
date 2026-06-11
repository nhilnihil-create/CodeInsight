#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void){
  int a,b,q,i,j,k;
  ll s[100005],t[100005],x,co1,co2,ans;
  ll *p1,*p2;
  
  cin >> a >> b >> q;
  for (i=0;i<a;i++) cin >> s[i];
  for (i=0;i<b;i++) cin >> t[i];
  
  for (i=0;i<q;i++){
    vector<ll> ap,bp;
    cin >> x;
    
    p1=lower_bound(s,s+a,x);
    p2=lower_bound(t,t+b,x);
    
    if (p1!=s) ap.push_back(*(p1-1)-x);
    if (p1!=s+a) ap.push_back(*p1-x);
    if (p2!=t) bp.push_back(*(p2-1)-x);
    if (p2!=t+b) bp.push_back(*p2-x);
    
    ans=1e12;
    for (j=0;j<ap.size();j++) for (k=0;k<bp.size();k++){
      co1=abs(ap[j])+abs(ap[j]-bp[k]);
      co2=abs(bp[k])+abs(bp[k]-ap[j]);
      ans=min({ans,co1,co2});
    }
    
    cout << ans << endl;
  }
  
  return 0;
}