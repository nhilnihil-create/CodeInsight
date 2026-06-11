#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  int i;
  for(i=0;i<n;i++) cin >> v[i];
  sort(v.begin(),v.end());
  int max = 0;
  int cnt = 0;
  for(i=0;i<n;i++){
    if(max<v[i]){
      cnt++;
      max = v[i];
    }
  }
  cout << cnt << "\n";
  return 0;
}