#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int main(){
  string s;
  cin>>s;
  stack<int> data;
  int cnt=0;
  for(int i=0;i<s.size();i++){
    int num=s.at(i)-48;
    //cout<<num<<endl;
    data.push(num);
    if(data.size()>=2){
      int v=data.top();
      data.pop();
      int u=data.top();
      data.pop();
      if(v*u==0&&(v==1||u==1)){
        cnt++;
      }else{
        data.push(u);
        data.push(v);
      }
    }
  }
  cout<<cnt*2<<endl;
}