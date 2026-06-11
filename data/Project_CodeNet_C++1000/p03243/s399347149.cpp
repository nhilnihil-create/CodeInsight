#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう

#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int x;
  int ans;
  cin>>x;
  for(int i=1;i<=9;i++){
    if(i*111>=x){
       ans=i*111;
      break;
    }
  }
  cout<<ans<<endl;
}
