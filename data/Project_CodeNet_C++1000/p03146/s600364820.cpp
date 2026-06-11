#include<iostream>
#include<vector>
using namespace std;
int main(){

  int s;
  cin>>s;
  bool flag=0;
  int n=1;
  vector<int>a(n);
  a[0]=s;
  while(flag==0){
    if(a[n-1]%2==1){
 
      n++;
      a.resize(n);
      a[n-1]=a[n-2]*3+1;
    }
    else{
          
      n++;
      a.resize(n);
      a[n-1]=a[n-2]/2;
    }
    for(int i=0;i<=n-2;i++){
    
      if(a[i]==a[n-1]){
        
        flag=1;
        break;
      }
    }
  }
 /* for(int i=0;i<=n-1;i++){
  
    cout<<a[i]<<endl;
  }*/
  cout<<n;
  return 0;
}