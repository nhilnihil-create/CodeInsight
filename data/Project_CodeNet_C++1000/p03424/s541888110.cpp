#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool tf=false;

  for(int i = 0; i < N; ++i){
    char arare;
    cin >> arare;
    if(arare=='Y')tf=true;
  }
  if(tf){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }
}

