#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  string C;
  cin >>N;
  int j = N-1;
  for (int i = 0; i < N; ){
  cin  >> C;
    if ( C =="Y"){
     cout << "Four" << endl; 
      break;
      }else if (C !="Y"){
      i++;
      }
    if (i==j)  {
      cout << "Three" << endl;
      }
    }
}
