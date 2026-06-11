#include <bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[]){
  int N,A,B,max,min;
  cin >> N >> A >> B;
  if(N>A+B) min = 0;
  else min = A+B-N;
  if(A>B) max = B;
  else max = A;
  cout << max << " " << min << endl;
  

  return 0;
}
