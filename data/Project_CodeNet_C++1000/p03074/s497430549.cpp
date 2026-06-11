#include <bits/stdc++.h>
using namespace std;
int main(){
  #define int long long
  int N,K;
  cin>>N>>K;
  string S;
  cin>>S;
  vector<int> l(0);//i番目の0の塊の左端
  vector<int> r(0);//右端
  //vector<int> l(0);//i番目の1の塊のサイズ
  for(int i=0;i<N;i++){
    if(i==0){
      if(S.at(i)=='0'){
        l.push_back(i);
      }
      if(S.at(i)=='0' && S.at(i+1)=='1'){
        r.push_back(i);
      }
    }
    else if(i==N-1){
      if(S.at(i)=='0'){
        r.push_back(i);
      }
      if(S.at(i)=='0' && S.at(i-1)=='1'){
        l.push_back(i);
      }
    }
    else{
      if(S.at(i-1)=='1' && S.at(i)=='0'){
        l.push_back(i);
      }
      if(S.at(i)=='0' && S.at(i+1)=='1'){
        r.push_back(i);
      }
    }
  }
  int count=l.size();
  if(count<=K){
    cout<<N<<endl;
    return 0;
  }
  int ans=0;
  for(int i=0;i<count-K+1;i++){
    int L=l.at(i);
    int R=r.at(i+K-1);
    if(L>0){
      while(S.at(L-1)=='1'){
        L--;
        if(L==0){
          break;
        }
      }
    }
    if(R<N-1){
      while(S.at(R+1)=='1'){
        R++;
        if(R==N-1){
          break;
        }
      }
    }
    ans=max(ans,R-L+1);
  }
  cout<<ans<<endl;
}