#include<iostream>
using namespace std;

int main(){
  string X, Y;
  cin >> X >> Y;
  if(X == Y){
    cout << "=" << endl;
    return 0;
  }
  cout << (X > Y ? ">" : "<") << endl;
  return 0;
}
