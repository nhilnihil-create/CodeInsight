#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pos;
int main(){
  long N;cin>>N;
  vector<long> A(N);for(int i=0;i<N;i++)cin>>A[i];
  
  long ans=0;
  
  if(A[N-1]<N)ans+=A[N-1];
  else {cout<<-1;return 0;}
  for(int i=N-2;i>=0;i--){
    //あり得るのは, 一個後に比べて
    //  1だけ小さい (この時自然に作れる)
    //  2以上小さい ありえない()
    //  同じかそれ以上 再度コストを図る
    if(A[i]<A[i+1]-1){cout<<-1;return 0;}
    else if(A[i]>=A[i+1]){
      if(A[i]>i){cout<<-1;return 0;}
      ans+=A[i];
    }
    else{
      
    } 
  }
  cout<<ans;

}