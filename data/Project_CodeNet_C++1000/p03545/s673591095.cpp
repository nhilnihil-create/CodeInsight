#include <bits/stdc++.h>
using namespace std;

bool kei(vector<int> &moji,vector<bool> &op,int n,int x,bool b){
  if(n==3){
    if(b){
      x+=moji.at(n);
    }else{
      x-=moji.at(n);
    }
    if(x==7){
      op.at(n)=b;
      return true;
    }else{
      return false;
    }
  }
  if(b){
    if(kei(moji,op,n+1,x+moji.at(n),true)){
      op.at(n) = b;
      return true;
    }else if(kei(moji,op,n+1,x+moji.at(n),false)){
      op.at(n) = b;
      return true;
    }
  }else{
    if(kei(moji,op,n+1,x-moji.at(n),true)){
      op.at(n) = b;
      return true;
    }else if(kei(moji,op,n+1,x-moji.at(n),false)){
      op.at(n) = b;
      return true;
    }
  }
  return false;
}
int main(){
  string str;
  cin >> str;
  vector<int>moji(str.size());
  vector<bool>op(str.size());
  for(long unsigned int i=0;i < str.size();i++){
    moji.at(i)= str.at(i)-48;
  }
  kei(moji,op,0,0,true);
  for(int i=0;i<3;i++){
    cout << moji.at(i);
    if(op.at(i+1))
      cout << "+";
    else
      cout << "-";
  }
  cout << moji.at(3) << "=7";
  cout << endl;
}
  