#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0,A=0,B=0;
  cin>>N;
  if(N>23){
    cout<<"0"<<endl;
  }
  else{
    vector<int> p(13);
    p.at(0)++;
    for(int i=0;i<N;i++){
      int b;
      cin>>b;
      p.at(b)++;
    }
    vector<int> iti;
    vector<int> t;
    for(int i=0;i<13;i++){
      if(p.at(i)==1){
        iti.push_back(i);
        B++;
      }
      else if(p.at(i)==2){
        t.push_back(i);
        t.push_back(24-i);
      }
      else if(p.at(i)>2){
        A++;
        break;
      }
    }
    if(A==1){
      cout<<"0"<<endl;
    }
    else{
    for(int j=0;j<(1<<B);j++){
      vector<int> q(N+1);
      for(int i=0;i<B;i++){
        if(j&(1<<i)){
          q.at(i)=iti.at(i);
        }
        else{
          q.at(i)=24-iti.at(i);
        }
      }
      for(int i=B;i<=N;i++){
        q.at(i)=t.at(i-B);
      }
      sort(q.begin(),q.end());
      int a=min(24+q.at(0)-q.at(N),q.at(N)-q.at(0));
      for(int i=0;i<q.size()-1;i++){
        a=min(a,q.at(i+1)-q.at(i));
      }
      Z=max(Z,a);
    }
    cout<<Z<<endl;
    }
  }
}