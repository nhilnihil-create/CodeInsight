#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
cin>>N;
int C,D;
bool singi=0;
  
  for(int c=0;c<=N;c++){
    for(int d=0;d<=N;d++){
        int total =4*c+7*d; //合計
        if (total==N)singi++;
      }
    }
  if(singi==true){
   cout<<"Yes"<<endl;
  }
  else{
  cout<<"No"<<endl;}
        
}