#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map> 
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

 
int main(){
  int n,x;
  cin >> n >> x;
  vector<int> v(n);
  int mn = 1e9;
  rep(i,n){
    cin >> v[i];
    x-= v[i];
    mn = min(mn,v[i]);
  }
  cout << n+(x/mn) << endl;

  
  
  return 0; 
}

