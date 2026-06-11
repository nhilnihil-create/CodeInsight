#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long int a[300];
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  bool flag=true;
  int c=0;
  
  do{
    for(int i=0;i<n;i++){
      if(a[i]%2==0) a[i]=a[i]/2;
      else flag=false;
    }
    if(flag) c++;
  }while(flag);

  cout<<c;

}
