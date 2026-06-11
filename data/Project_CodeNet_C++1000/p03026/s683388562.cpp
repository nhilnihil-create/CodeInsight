#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<vector<long>>A(N);
  for(long i=0;i<N-1;i++){
    long a,b;cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  vector<long>C(N),D(N,-1);
  for(long i=0;i<N;i++)cin>>C[i];
  sort(C.begin(),C.end(),greater<long>());
  
  queue<long>q;q.push(0);//D[0]=C[0];
  long l=0;
  while(q.size()){
    long f=q.front();q.pop();
    D[f]=C[l];l++;
    for(long n:A[f]){
      if(D[n]==-1)q.push(n);
    }
  }
  
  long s=0;for(long i=1;i<N;i++)s+=C[i];
  cout<<s<<endl;
  for(long i=0;i<N;i++)cout<<D[i]<<" ";
}