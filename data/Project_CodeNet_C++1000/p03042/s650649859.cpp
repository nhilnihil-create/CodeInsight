#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

ifstream in("bleach.in");
ofstream out("bleach.out");

int const NMAX = 1e6;
int v[1 + NMAX];

int main() {

  string inp;
  cin >> inp;
  if((inp[0] - '0') * 10 + (inp[1] - '0') <= 12 && (inp[2] - '0') * 10 + (inp[3] - '0') <= 12 && (inp[0] - '0') * 10 + (inp[1] - '0') != 0 && (inp[2] - '0') * 10 + (inp[3] - '0') != 0){
    cout << "AMBIGUOUS";
  }else if((inp[0] - '0') * 10 + (inp[1] - '0') <= 12 && (inp[0] - '0') * 10 + (inp[1] - '0') != 0){
    cout << "MMYY";
  }else if((inp[2] - '0') * 10 + (inp[3] - '0') <= 12 && (inp[2] - '0') * 10 + (inp[3] - '0') != 0){
    cout << "YYMM";
  }else{
    cout << "NA";
  }
  return 0;
}
