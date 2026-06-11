#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> count(4,0);
  int a,b;
  for(int i=0;i<3;i++){
    cin >> a >> b;
    a--;
    b--;
    count.at(a)++;
    count.at(b)++;
    if(count.at(a)>=3||count.at(b)>=3){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
