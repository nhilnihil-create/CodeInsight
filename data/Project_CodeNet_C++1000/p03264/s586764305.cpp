#include <iostream>
using namespace std;
 
int k,odd,even;
int main() {
    cin>>k;
  if(k>1){
  even=k/2;
  odd=k-even;
  cout<<even*odd;
  }
}
