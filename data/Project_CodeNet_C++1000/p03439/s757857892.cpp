#include <iostream>
using namespace std;

int main(void){
  int N;
  cin >> N;
  
  int isOK,isNG,mid;
  string A;
  
  cout << "0" << endl;
  fflush(stdout);
  cin >> A;
  if(A=="Male")
    isOK = 0;
  else if(A=="Female")
    isNG = 0;
  else
    return 0;
  
  cout << N-1 << endl;
  fflush(stdout);
  cin >> A;
  if(A=="Male")
    isOK = N-1;
  else if(A=="Female")
    isNG = N-1;
  else
    return N-1;
  
  while(true){
    mid = (isOK+isNG)/2;
    cout << mid << endl;
    fflush(stdout);
    cin >> A;
    if((A=="Male"&&mid%2==0)||(A=="Female"&&mid%2==1))
      isOK = mid;
    else if((A=="Male"&&mid%2==1)||(A=="Female"&&mid%2==0))
      isNG = mid;
    else
      return mid;
  }
}
