#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  int newc=10001;
  int cnt=0;
  for (int i=0;i < n;i++) cin >> v.at(i);
  for (int j=0; j < n-1; j++){
    if (v.at(j)==v.at(j+1)) {
      v.at(j+1)=newc;
      newc++;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}