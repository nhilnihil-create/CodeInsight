#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,k;
  cin >> n >> k;

  cout << setprecision(13); 
  double ans=0;
  
  rep(i,n){
    double p=i+1;
    if(p>=k){ans+=double(1.0/n); continue;}
    double q = double((1.0/n))*pow(0.5,ceil(log2(k)-log2(p)));
    ans += q;
    //cout << q << endl;
  }

  cout << ans;
}