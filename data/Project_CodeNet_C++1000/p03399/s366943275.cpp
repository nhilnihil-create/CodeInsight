#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,cnt=0;
  cin >> A >> B >> C >> D;
  if(A>B){
    cnt += B;
  }else{
    cnt += A;
  }
  if(C>D){
    cnt += D;
  }else{
    cnt += C;
  }
  cout << cnt << endl;
}
