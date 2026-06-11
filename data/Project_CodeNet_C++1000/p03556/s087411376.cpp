#include<iostream>
using namespace std;
int main(){
  long long int n,i=1,ans=0;
  cin>>n;
  while(1){
    long long int s=i*i;
    if(s>n) break;
    else ans=s;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}
