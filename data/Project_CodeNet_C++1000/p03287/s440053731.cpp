#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,M;cin>>N>>M;
  vector<long>A(N);for(long i=0;i<N;i++)cin>>A[i];
  //vector<long>C(M,0);//割った余りがiである回数
  unordered_map<long,long>C;
  long s=0;//累積和%M
  long ans=0;
  for(long i=0;i<N;i++){
    s=(s+A[i])%M;
    //r=iで条件を満たす組は, 
    //それより左で累積和がM-sになるもの
    //s[r] -s[l-1] %M==0 ; 余りが等しい回数
    ans+=C[s];
    C[s]++;if(s==0)ans++;
  }
  cout<<ans;
}

