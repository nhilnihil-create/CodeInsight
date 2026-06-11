#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  int S=N;
  vector<int> a(N);
  int b[N+1]={0};
  bool flag=0;
  for (int i=0;i<N;i++) cin>>a[i];
  do{
    
    for (int i=N-1;i>=0;i--){
      if(a[i]==i+1){
        b[N]=i+1;
        //cout<<b[N]<<"#"<<N<<endl;
        a.erase(a.begin()+i);
        flag=0;
        N--;
        if(N==0){
          for(int k=1;k<=S;k++){
            cout<<b[k]<<endl;
          }
            return 0;
        }
        break;
      }
    }
    if(flag){
      cout<<"-1"<<endl;
      return 0;
    }
    flag=1;
      
  }
  while (N>-1);
  return 0;
}

  
      
        