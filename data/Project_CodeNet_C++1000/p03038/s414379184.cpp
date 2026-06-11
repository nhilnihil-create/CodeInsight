#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,M;
  cin>>N>>M;
  vector<long long>A(N,0);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  
  vector<pair<long long,long long>>vec;
  for(int i=0;i<M;i++){
    long long b,c;
    cin>>b>>c;
    vec.emplace_back(c,b);
  }
  
  sort(vec.begin(),vec.end());
  
  int temp1=0;
  int temp2=0;
  int temp3=0;
  while(1){
    if(A[temp1]<vec[M-1-temp2].first && vec[M-1-temp2].second-temp3>0){
      A[temp1]=vec[M-1-temp2].first;
      temp1++;
      temp3++;
      continue;
    }
    if(A[temp1]<vec[M-1-temp2].first && vec[M-1-temp2].second-temp3==0){
      temp2++;
      temp3=0;
      continue;
    }
    break;
  }

  long long sum=0;
  for(int i=0;i<N;i++){
    sum=sum+A[i];
  }
  cout<<setprecision(18)<<sum<<endl;
  return 0;
}

 