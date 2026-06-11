#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  for(int i=N;i>=1;i--){
    double x=sqrt(i);
    if(x==(int)x){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
