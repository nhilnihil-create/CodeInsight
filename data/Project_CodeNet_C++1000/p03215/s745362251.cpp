#include<bits/stdc++.h>
using namespace std;
int main(){
  
  /*
  和のbit AND
  普通に全探索すれば
  部分列の選び方O(N^2)
  
  部分列からbitを計算するので
  N^2 C K
  だからやばい
  
  
  まず和を計算したのち, ソート??
  bitで見れば早い
  
  */
  long N,K;cin>>N>>K;
  vector<long>A(N),S(N+1,0);
  for(long i=0;i<N;i++){
    cin>>A[i];S[i+1]=S[i]+A[i];
  }
  list<long>SS;
  for(long i=0;i<N;i++)for(long j=i;j<N;j++){
    SS.push_back(S[j+1]-S[i]);
  }

  long ans=0;
  for(long b=LONG_MAX-(LONG_MAX/2);b>0;b/=2){
    long c=0;
    for(auto itr=SS.begin();itr!=SS.end();itr++){
      if(b&(*itr))c++;
    }
    if(c>=K){
      for(auto itr=SS.begin();itr!=SS.end();itr++){
        if(!(b&(*itr))){
          itr=SS.erase(itr);itr--;
        }
      }ans|=b;
    }
  }
  cout<<ans;
    
}