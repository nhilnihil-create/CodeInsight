#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; 
  cin >>n;
  priority_queue<int>q;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    q.push(a);
  }
  int a,b,amari; 
  while(q.size()>0){
    if(q.size()==1){
      amari=q.top();q.pop();
      break;
    }else if(q.size()==2){
      a=q.top();q.pop();
      b=q.top();q.pop();
      //cout<<a<<" "<<b<<endl;
      a-=b;;
      if(a>0&&b>0){
        q.push(a);
        q.push(b);
      }else{
        amari=b;
      }
    }else{
      a=q.top();q.pop();
      b=q.top();q.pop();
      amari=a%b;
      if(amari!=0)q.push(amari);    
    }
  }
  cout<<amari<<endl;
  return 0;
}
