#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>X(N);
  vector<int>Xcopy(N);
  for(int i=0;i<=N-1;i++)cin>>X[i];
  Xcopy=X;
  sort(X.begin(),X.end());
  int check1=X[N/2-1];
  int check2=X[N/2];
  for(int i=0;i<=N-1;i++){
  
    if(Xcopy[i]<=check1)cout<<check2<<endl;
    else cout<<check1<<endl;
  }
  return 0;
}