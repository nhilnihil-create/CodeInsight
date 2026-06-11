#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long long M=0;
  long long AA=0;
  long long BB=0;
  long long SS=0;
  cin>>N;
  vector<string>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    string S=vec.at(X);
    for(int Y=0;Y<S.size()-1;Y++){
      if(S.at(Y)=='A'&&S.at(Y+1)=='B'){
        M++;
      }
    }
    if(S.at(S.size()-1)=='A'){
      AA++;
    }
    if(S.at(0)=='B'){
      BB++;
    }
    if(S.at(S.size()-1)=='A'&&S.at(0)=='B'){
      SS++;
    }
  }
  if(SS==AA&&SS==BB&&AA!=0&&BB!=0){
    M--;
    cout<<M+AA<<endl;
  }
  else{
    cout<<M+min(AA,BB)<<endl;
  }
}