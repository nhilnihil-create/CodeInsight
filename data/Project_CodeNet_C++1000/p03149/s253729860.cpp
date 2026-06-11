#include <iostream>
#include <algorithm>
using namespace std;
int a[4];
int x[4]={1,4,7,9};
int main(){
  for(int i=0;i<4;i++)cin>>a[i];
  sort(a,a+4);
  for(int i=0;i<4;i++){
    if(a[i]!=x[i]){
      cout<<"NO\n";
      return 0;
    }
  }
  cout<<"YES\n";
  return 0;
}