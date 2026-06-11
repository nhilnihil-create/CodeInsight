#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  int max=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(max<a[i]){
      max=a[i];
    }
  }
  
  int num[n]={0};
  int count=0;
  for(int i=0;i<n;i++){
    num[a[i]]++;
    if(num[a[i]]==1){
      count++;
    }
  }
  sort(num,num+n,greater<int>());
  int p=0;
  for(int i=0;i<k;i++){
     n-=num[i];
  }
   if(n>0){
    cout<<n<<endl;
  }else{
     cout<<0<<endl;
   }
}
 
