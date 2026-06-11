#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  int A,B;
  cin>>A>>B;
  string S;
  cin>>S;
  rep(i,A){
    if(S[i]=='-'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(S[A]!='-'){
    cout<<"No"<<endl;
    return 0;
  }
  for(int i=A+1;i<A+B+1;i++){
    if(S[i]=='-'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}