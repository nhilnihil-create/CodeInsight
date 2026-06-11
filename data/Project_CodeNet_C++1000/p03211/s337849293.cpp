#include <bits/stdc++.h>
using namespace std;

int ctoi(char c){
  if(c == '0') return 0;
  if(c == '1') return 1;
  if(c == '2') return 2;
  if(c == '3') return 3;
  if(c == '4') return 4;
  if(c == '5') return 5;
  if(c == '6') return 6;
  if(c == '7') return 7;
  if(c == '8') return 8;
  if(c == '9') return 9;
}
int zettai(int n){
  if(n < 0)n *= (-1);
  return n;
}
  
 
int main() {
  string S;
  cin >> S;
  int minx = 1000;
  for(int i = 0; i < S.size() - 2; i++){
    int x = ctoi(S.at(i))*100 + ctoi(S.at(i+1))*10 + ctoi(S.at(i + 2));
    //cout << "; " << x << endl;
    if(x < 0) x *= (-1);
    minx = min(zettai(753 - x), minx);
    //cout << minx << endl;
  }
  cout << minx << endl;
}
    
    