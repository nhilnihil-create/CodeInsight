#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  double A[N];
  double sum=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    sum+=A[i];
  }
  int ans=-1;
  double dif=1000;
  double ave=sum/N;
  for(int i=0;i<N;i++){
    if(abs(A[i]-ave)<dif){
      dif=abs(A[i]-ave);
      ans=i;
    }
    //cout<<A[i]<<" "<<i<<" "<<dif<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
