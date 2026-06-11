#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string a;
  cin >> a;
  int b=0,c=0;
  for(int i=0;i<4;i++){
    if(a.at(i)=='+')b++;
    else c++;
  }
  cout << b-c;
}
