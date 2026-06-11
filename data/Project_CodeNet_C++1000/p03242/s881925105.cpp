#include <iostream>
using namespace std;

int main() {
  int x =911;
  cin >> x;
  string y=to_string(x);
  if(y[0]=='1'){
    y[0]='9';
  } else{
    y[0]='1';
  }
  if(y[1]=='1'){
    y[1]='9';
  } else{
    y[1]='1';
  }
  if(y[2]=='1'){
    y[2]='9';
  } else{
    y[2]='1';
  }
	cout<<y;
	return 0;
}
