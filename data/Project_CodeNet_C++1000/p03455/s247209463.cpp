#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <math.h>
 
using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
 
	int x,y,z;
	cin >> x >> y;
    z = x*y;
  
    if(z%2==0){
      cout << "Even" << "\n";
    }else{
      cout << "Odd" << "\n";
    }
  
}