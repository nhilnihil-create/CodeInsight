#include <iostream>
#include <string>
using namespace std;
int main(){
  int N;
  cin>>N;
  cout<<0<<endl;
  string s;
  cin>>s;
  int right=0;
  int left=N;
  while(s!="Vacant"){
    int mid=(right+left)/2;
    cout<<mid<<endl;
    string t;
    cin>>t;
    if((mid-right)%2==0){
      if(s==t) right=mid;
      else left=mid+1;
    }
    else{
      if(s==t) left=mid+1;
      else right=mid;
    }
    if(right==mid||t=="Vacant") s=t;
  }
  
  return 0;
}