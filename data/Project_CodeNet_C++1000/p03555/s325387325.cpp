#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<char> c1(3), c2(3);
  for(int i = 0; i < 3; i++){
    cin >> c1.at(i);
  }
  for(int i = 0; i < 3; i++){
    cin >> c2.at(i);
  }
  
  if(c1.at(0) == c2.at(2) && c1.at(1) == c2.at(1) && c1.at(2) == c2.at(0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}