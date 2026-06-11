#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  int N;
  cin>>N;
  int t[N];
  int x[N];
  int y[N];
  t[0]=x[0]=y[0]=0;
  for(int i=0;i<N;i++){
    cin>>t[i+1]>>x[i+1]>>y[i+1];
  }
  for(int j=0;j<N;j++){
    int dt=abs(t[j+1]-t[j]);
    int dx=abs(x[j+1]-x[j]);
    int dy=abs(y[j+1]-y[j]);
    if(dt-(dx+dy)<0){
      cout<<"No"<<endl;
      return 0;
    }
    if(dt%2!=(dx+dy)%2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
    
 
}

  
  