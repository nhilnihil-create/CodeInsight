#include<iostream>
#include<algorithm>
using namespace std;
const int INF=100000;
int main(){
  int n;
  int limit;
  cin>>n>>limit;
  
  int minimum=INF;
  for(int i=0;i<n;i++){
    int c,t;
    cin>>c>>t;
    if(t<=limit){
      minimum=min(minimum,c);
    }
  }
  if(minimum==INF){
    cout<<"TLE"<<endl;
  }else{
    cout<<minimum<<endl;
  }
  return(0);
}