#include <bits/stdc++.h>
using namespace std;

string jisho1(string &a){
  char moji1, moji2;
  for(int i;i<a.size()-1;i++){
    moji1=a.at(i);
    moji2=a.at(i+1);
    if(moji1 <= moji2){
      continue;
    }
    else{
      a.at(i)=moji2;
      a.at(i+1)=moji1;
      a=jisho1(a);
    }
  }
  return a;
}
string jisho2(string &a){
  char moji1, moji2;
  for(int i;i<a.size()-1;i++){
    moji1=a.at(i);
    moji2=a.at(i+1);
    if(moji1 >= moji2){
      continue;
    }
    else{
      a.at(i)=moji2;
      a.at(i+1)=moji1;
      a=jisho2(a);
    }
  }
  return a;
}
int main(){
  string b,c;
  cin>>b>>c;
  b=jisho1(b);
  c=jisho2(c);
  if(b>=c){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}