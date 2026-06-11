#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  ll n;
  cin >> n;
  rep(i,3500){
    rep(j,3500){
      ll a=4*(j+1)*(i+1)-n*(j+i+2);
      if(a>0){
        if(n*(i+1)*(j+1)%a==0){
          cout << i+1 << " " << j+1 << " " << n*(i+1)*(j+1)/a << endl;
          return 0;
        }
      }
    }
  }
}
