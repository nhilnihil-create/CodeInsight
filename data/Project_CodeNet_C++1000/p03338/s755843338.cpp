#include<bits/stdc++.h>
using namespace std;

int func(string T,string U){
  int count=0;
  for(char C='a';C<='z';C++){
    bool t=false;
    bool u=false;
    for(int i=0;i<T.size();i++){
      if(T.at(i)==C){
        t=true;
      }
    }
    for(int i=0;i<U.size();i++){
      if(U.at(i)==C){
        u=true;
      }
    }
    if(t && u){
      count++;
    }
  }
  return count;
}
    
 
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int maxcount=0;
  for(int i=1;i<N;i++){
    string T=S.substr(0,i);
    string U=S.substr(i,N-i);
    int count=func(T,U);
    maxcount=max(count,maxcount);
  }
  cout << maxcount << endl;
}
  