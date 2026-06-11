#include <iostream>
using namespace std;
 
int main(){
 
  int n,max=0,sum=0;
  cin >> n;
  int a;
  for(int i=0; i<n; ++i){
    cin >> a;
    sum += a;
    max = (a>max)? a:max;
  }
  if(max<(sum-max)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}