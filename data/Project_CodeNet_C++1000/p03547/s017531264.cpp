#include <iostream>
using namespace std;
int main(){
  char C[6] = {'A','B','C','D','E','F'};
  char A,B;
  int a,b;
  cin >> A >> B;
  for(int i = 0; i < 6; i++){
    if(C[i] == A) a = i;
    if(C[i] == B) b = i;
  }
  if(a > b) cout << ">" << endl;
  else if(a < b) cout << "<" << endl;
  else cout << "=" << endl;
}
