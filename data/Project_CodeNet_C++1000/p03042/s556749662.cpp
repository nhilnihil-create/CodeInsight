#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  string S;
  cin >> S;
  string x,y;
  x += S.at(0);
  x += S.at(1);
  y += S.at(2);
  y += S.at(3);
  int xx = stoi(x);
  int yy = stoi(y);
  if((1 <= xx && xx <= 12) && (1 <= yy && yy <= 12)){
    cout << "AMBIGUOUS" << endl;
  }else if(1 <= xx && xx <= 12){
    cout << "MMYY" << endl;
  }else if(1 <= yy && yy <= 12){
    cout << "YYMM" << endl;
  }else{
    cout <<"NA" << endl;
  }
}
