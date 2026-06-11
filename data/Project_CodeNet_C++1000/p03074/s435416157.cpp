#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  string S;
  cin>>S;
  int cnt=1;
  int cntmax=1;
  int temp=1;
  int flag=0;
  queue<int>Q;
  if(S.at(0)=='0'){
    flag=0;
    K--;
  }
  else {
    flag=1;
  }

  for(int i=1;i<N;i++){
    //cout<<"flag"<<flag<<"temp"<<temp<<"cnt"<<cnt<<endl;
    if(flag==0 && S.at(i)=='0'){
      cnt++;
      temp++;
      cntmax=max(cntmax,cnt);
       continue;
    }
    if(flag==0 && S.at(i)=='1'){
      Q.push(temp);
      flag=1;
      cnt++;
      temp=1;
      cntmax=max(cntmax,cnt);
      continue;
    }
    
    if(flag==1 && S.at(i)=='1'){
      cnt++;
      temp++;
      cntmax=max(cntmax,cnt);
       continue;
    }    
    if(flag==1 && S.at(i)=='0'){
      K--;
      flag=0;
      if(K<0){
        cnt-=Q.front();
        Q.pop();
      }
      cnt++;  
      temp++;
      cntmax=max(cntmax,cnt);
    }
  }
  
  cout<<cntmax<<endl;
  
  return 0;
}
