#include <iostream>
#include <vector>
using namespace std;
int main(void){
  vector<int>num(4,0);
  for(int i=0;i<4;i++){
    cin >> num[i];
  }
  
  vector<int>check(10,0);
  for(int i=0;i<4;i++){
    check[num[i]]++;
  }
  
  if(check[1] == 1 && check[4] == 1 && check[7] == 1 && check[9] == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}
