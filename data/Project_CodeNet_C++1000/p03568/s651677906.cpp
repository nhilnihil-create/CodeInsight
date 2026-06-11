#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  cin >> n;
  ll ans=1;
  vector<int> v(n);
  rep(i,n){
    cin >> v[i]; 
    ans*=3;
  }
  ll cnt=1;
  for (int i=0;i < n;i++){
    int tmp=0;
    for (int j=-1;j <2;j++){
      if ((v[i]+j)%2==1) tmp++; 
    }
    cnt*=tmp;
  }
  cout << ans-cnt << endl;
  
  
  return 0;
}

