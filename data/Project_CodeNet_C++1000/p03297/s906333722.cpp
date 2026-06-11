#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

ll gcd(ll a, ll b) {
  if(a < b) gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll t;
  cin >> t;
  ll a[t],b[t],c[t],d[t];
  rep(i,t) cin >> a[i] >> b[i] >> c[i] >> d[i];
  rep(i,t){
    if(a[i]<b[i] || b[i]>d[i]){
      cout << "No" << endl;
      continue;
    }  
    ll g=gcd(b[i],d[i]);
    ll mg=(a[i]-b[i]+1+(g-1))/g*g;
    //    cout << mg << " " << c[i]-a[i]+1 << endl;
    if(mg<=a[i]-c[i]-1){
      cout << "No" << endl;
    }
    else cout << "Yes" << endl;
    /*    
    bool say=false;
    if(b[i]-c[i]>2*g){
      cout << "No" << endl;
      continue;
    }
    for(ll j=c[i]-a[i]+1;j<b[i]-a[i];j++){
      if(j%g==0){
	//      cout << j << endl;
	cout << "No" << endl;
	say=true;
	break;
      }
      //    if(j==b[i]-a[i]-1) cout << "Yes" << endl;
    }
    if(!say) cout << "Yes" << endl;   */
  }
  

  
  return 0;
    

}
