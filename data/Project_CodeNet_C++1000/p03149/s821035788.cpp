#include <iostream>
using namespace std;

int main(void) {
  int N1,N2,N3,N4;
  cin >> N1 >> N2 >> N3 >> N4;
  
  int num[10];
  num[N1] = 1;
  num[N2] = 1;
  num[N3] = 1;
  num[N4] = 1;
  int ok = 0;
  if(num[1]==1 && num[9]==1 && num[7] ==1 && num[4] == 1)
    ok = 1;
  if(ok)
  	cout <<"YES" << endl;
  else
    cout << "NO" << endl;
 return 0; 
}