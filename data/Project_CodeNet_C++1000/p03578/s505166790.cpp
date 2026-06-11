#include <iostream>
#include <map>
using namespace std;
int main(){
  int n; cin >> n;
  map<long long int, int> D;
  for(int i=0;i<n;i++){
    long long int d; cin >> d;
    D[d]++;
  }
  string ans="YES";
  int m; cin >> m;
  for(int i=0;i<m;i++){
    long long int t; cin >> t;
    D[t]--;
    if(D[t]<0) {
      ans="NO";
      break;
    }
  }
  cout << ans << endl;
}