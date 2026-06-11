#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int main(){
  int A, B, C, X;
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;
  
  int res = 0;
  for(int i=0;i<=A;i++){
    for(int k=0;k<=B;k++){
      int l = X-500*i-100*k;
      if (l%50 == 0 && 0<=l && l/50<=C){
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
