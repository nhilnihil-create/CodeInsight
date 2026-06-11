#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  
  bool yn=false;
  
  for(int i=0;i<N/7+1;i++){
    bool fin=false;
    for(int j=0;j<N/4+1;j++){
      if(4*j+7*i==N){
        yn=true;
        fin=true;
        break;
      }
    }
    if(fin==true)break;
  }
  
  if(yn==true)cout << "Yes"<<endl;
  else cout<<"No"<<endl;
  
}