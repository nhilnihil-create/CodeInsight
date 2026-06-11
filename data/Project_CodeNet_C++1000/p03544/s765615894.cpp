#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int64_t L1,L2,L3;
  L1=2;
  L2=1;
  if(N==1){
    cout << 1 << endl;
  }else{
    for(int i=0;i<N-1;i++){
      L3=L2+L1;
      L1=L2;
      L2=L3;
    }
    cout << L3 << endl;
  }
}
