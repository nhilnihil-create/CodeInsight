#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[100];
  int h=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(abs(a[i])>abs(a[h])) h = i;
  }

  cout<<2*n -1<<endl;

  for(int i=0;i<n;i++)
    cout<<h+1<<" " <<i+1<<endl;

  if(a[h]>0){
    for(int i=0;i<n-1;i++)
      cout<<i+1<<" "<<i+2<<endl;
  }
  else{
    for(int i=n;i>1;i--)
      cout<<i<<" "<<i-1<<endl;
  }

  return 0;
}
