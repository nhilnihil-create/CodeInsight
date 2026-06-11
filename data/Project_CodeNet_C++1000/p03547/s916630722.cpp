#include<iostream>
using namespace std;
int main(){
  char x,y;
  cin >> x >> y;
  if(x<y)
    cout << "<" << endl;
  if(y<x)
    cout << ">" << endl;
  if(y==x)
    cout << "=" << endl;
  return 0;
}
