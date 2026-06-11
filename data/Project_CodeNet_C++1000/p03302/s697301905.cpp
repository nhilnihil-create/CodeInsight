#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
	
  string s;
  int a,b,c,d,i,j,k;
  
  cin >> a;
  cin >> b;
	
  if(a+b==15){
    cout <<"+" <<endl;
  }else if(a*b==15){
	cout <<"*" <<endl;
  }else{
    cout << "x" <<endl;
  }
  
  return 0;
}
