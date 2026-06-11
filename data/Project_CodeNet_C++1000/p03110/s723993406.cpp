#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<pair<double,string>>A(N);
  for (int i=0; i<N; i++)cin>>A[i].first>>A[i].second;
  double sum=0;
  for (int i=0; i<N; i++){
    if(A[i].second=="JPY")sum+=A[i].first;
    else sum+=A[i].first*380000;
  }
  cout<<fixed<<setprecision(5)<<sum<<endl;
}
