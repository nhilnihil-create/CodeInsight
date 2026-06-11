#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int a[n]; cin>>a[0];
  int c=1; int sum=0;
  for(int i=1; i<n; i++){
    cin >> a[i];
    if(a[i]==a[i-1]){c++;}
    else if(c>1){sum=sum+c/2; c=1;}
  }
  if(c>1){sum=sum+c/2;}
  
  cout<<sum;
  
  return 0;
}