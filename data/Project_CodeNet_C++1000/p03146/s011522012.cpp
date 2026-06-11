#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int s;
  cin>>s;
  vector<int> a(1000001);
  a[1]=s;
  for(int i=2;i<1000001;i++){
    if(a[i-1]%2==0){
      a[i]=a[i-1]/2;
    }
    if(a[i-1]%2==1){
      a[i]=a[i-1]*3+1;
    }
  }
  for(int i=2;i<1000001;i++){
    for(int j=0;j<i;j++){
      if(a[i]==a[j]){
        cout<<i<<endl;
        return 0;
      }
    }
  }
}