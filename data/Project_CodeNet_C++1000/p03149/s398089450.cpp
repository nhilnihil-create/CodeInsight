#include <iostream>
using namespace std;

int main(){
  long N1, N2, N3, N4;
  char ans;
  cin >> N1 >>N2 >>N3 >>N4;
  int c;
  c=0;
  if(N1 == 1 || N2 == 1 || N3 == 1 || N4 == 1){
      c++;

  }
  if(N1 == 9|| N2 == 9 || N3 == 9 || N4 == 9){
      c++;

  }
  if(N1 == 7 || N2 == 7 || N3 == 7 || N4 == 7){
      c++;

  }
  if(N1 == 4 || N2 == 4 || N3 == 4 || N4 == 4){
      c++;

  }
  if(c==4){
    cout <<"YES";
  }
  else
  {
    cout << "NO";
  }
  return 0;
}
