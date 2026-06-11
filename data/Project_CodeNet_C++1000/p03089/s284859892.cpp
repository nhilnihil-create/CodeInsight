#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>B(N);
  for(int i=0;i<N;i++)
    cin>>B.at(i);
  vector<int>A;
  bool ans=true;
  for(int i=0;i<N;i++){
  int M=B.size();
    bool x=false;
    
    for(int j=M-1;0<=j;j--)
    if(B.at(j)-j==1){
    x=true; A.push_back(B.at(j));
      B.erase(B.begin()+j);
      break;
    }
    
     if(!x){ans=false; break;}
  }if(!ans)
    cout<<-1<<endl;
  else{
  int n=A.size();
    for(int i=n-1;0<=i;i--)
      cout<<A.at(i)<<endl;
  
  }
   return 0;
}
