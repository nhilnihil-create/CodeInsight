#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,A=0;
  cin>>H>>W;
  vector<char> p(H*W);
  queue<int> q;
  vector<int> r(H*W,-1);
  for(int i=0;i<H*W;i++){
    cin>>p.at(i);
    if(p.at(i)=='#'){
      q.push(i);
      r.at(i)=0;
    }
  }
  
  while(!q.empty()){
    int a=q.front();
    q.pop();
    if(r.at(a)>A){
      A++;
    }
    if(a>=W){
      if(r.at(a-W)==-1){
        r.at(a-W)=r.at(a)+1;
        q.push(a-W);
      }
    }
    if(a+W<H*W){
      if(r.at(a+W)==-1){
        r.at(a+W)=r.at(a)+1;
        q.push(a+W);
      }
    }
    if(a%W!=0){
      if(r.at(a-1)==-1){
        r.at(a-1)=r.at(a)+1;
        q.push(a-1);
      }
    }
    if(a%W!=W-1){
      if(r.at(a+1)==-1){
        r.at(a+1)=r.at(a)+1;
        q.push(a+1);
      }
    }
  }
  cout<<A<<endl;
    
}