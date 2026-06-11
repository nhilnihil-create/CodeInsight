#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector <int> pn;
  int p[60000];
  for(int i=0;i<55556;i++){
    p[i]=1;
  }

  for(int i=2;i*i<55555;i++){
    for(int j=2;j*i<56000;j++){
      p[i*j]=0;
    }
  }

  pn.emplace_back(2);
  pn.emplace_back(3);
  for(int i=4;i<55556;i++){
    if(p[i]==1){
      pn.emplace_back(i);
    }
  } 
  int k=0;
  while(n){
    if(pn[k]%5==3){
      cout<<pn[k];
      n--;
      if(n){
        cout<<" ";
      }
    }
    k++;
  }
  cout<<endl;
  return 0;
}
 
  