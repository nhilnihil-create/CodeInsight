#include<iostream><string>
using namespace std;
int main(){

  int A,B;
  cin>>A>>B;
  string S;
  cin>>S;
  for(int i=0;i<=A+B;i++){
  
    if(i==A){
    
      if(S[i]!='-'){
      
        cout<<"No";
        return 0;
      }
    }
    else{
    
      if(S[i]=='0'||S[i]=='1'||S[i]=='2'||S[i]=='3'||S[i]=='4'||S[i]=='5'||S[i]=='6'||S[i]=='7'||S[i]=='8'||S[i]=='9'){
      
      }
      else{
      
        cout<<"No";
        return 0;
      }
    }
  }
  cout<<"Yes";
  return 0;
}