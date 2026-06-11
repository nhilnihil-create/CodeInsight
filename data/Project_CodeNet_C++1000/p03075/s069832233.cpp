#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<int> v(5);
  int i,j,k;
  for(i=0;i<5;i++) cin >> v[i];
  cin >> k;
  sort(v.begin(),v.end());
  for(i=0;i<4;i++){
    for(j=i;j<5;j++){
      if(v[j]-v[i]>k){
        cout << ":(" << "\n";
        return 0;
      }
    }
  }
  cout << "Yay!" << "\n";
  return 0;
}