#include <bits/stdc++.h>
using namespace std;
int func(string a,string b){
  if(a.at(a.size()-1)==b.at(0))
    return 1;
  return 0;
}
int main(){
  int N;
  cin>>N;
  vector<string> p(N);
  for(int i=0;i<N;i++)
    cin>>p.at(i);
  int a=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      if(p.at(j)==p.at(i)){
        a=0;
        break;
      }
    }
  }
  int b=1;
  for(int i=0;i<N-1;i++){
    if(func(p.at(i),p.at(i+1))!=1){
      b=0;
      break;
    }
  }
  if(a==1 && b==1)
    cout<<"Yes"<<endl;
  else 
    cout<<"No"<<endl;
}
