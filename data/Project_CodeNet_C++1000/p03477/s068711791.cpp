#include <iostream>

using namespace std;

int main()
{
  int a, b, c, d, ab, cd;
  cin >> a >> b >> c >> d;
  ab = a + b;
  cd = c + d;
  if(ab < cd){
  	cout << "Right";
  }
  else if(ab > cd){
  	cout << "Left";
  }
  else cout << "Balanced";
  cout << endl;
}