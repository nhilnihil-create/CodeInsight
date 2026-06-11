#include <iostream>
using namespace std;
int main(){
  int A;
  int B;
  cin>>A;
  cin>>B;
if (B%2 == 0)
    {
      if (A >= 13)
      {
        cout<< B;
      }
      else if(A <= 12 && A >= 6)
      {
        cout<< B/2;
      }
      else 
      {
        cout<<0;
      } 
    }

}
