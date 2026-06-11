#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)


int main(){
  int n,k;
  cin >> n >> k;
  int now = 1;
  rep(i,n){
    now = min(now*2,now+k);
  }
  cout << now << endl;



  

  return 0;
   

}
