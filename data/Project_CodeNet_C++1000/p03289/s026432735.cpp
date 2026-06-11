#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string S;
  cin>>S;
  int a=S.size();
  bool ans=true;
  if(S[0]!='A'){
      ans=false;
  }
  int cnt=0;
    for(int i=2; i<a-1; i++){
        if(S[i]=='C'){
            cnt++;
        }
    }
  	if(S[S.size()-1]=='C'){
		ans=false;
      	
    }
    if(cnt!=1){
        ans=false;      
    }
  int g=0;
  rep(i,a){
    if (isupper(S[i])){
      g++;
    }
  }
  if(g!=2){
  ans=false;}
  if(ans==true){
      cout<<"AC"<<endl;
  }
  else{
      cout<<"WA"<<endl;
  }
}
