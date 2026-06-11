#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  
  map<int,int> dic;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    dic[a]++;
  }
  int sum=0;
  for(auto & x:dic){
    if(x.first>x.second){
      sum+=x.second;
    }
    else{
      sum+=(x.second-x.first);
    }
  }
  cout<<sum<<endl;
    
}