#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>A(N+2);
  for(int i=1;i<=N;i++)
    cin>>A.at(i);
  A.at(0)=0;
  A.at(N+1)=0;
  int sum=0;
  for(int i=0;i<=N;i++)
    sum+=abs(A.at(i)-A.at(i+1));
  for(int i=1;i<=N;i++){
  if(A[i-1]<A[i] && A[i+1]<A[i]){
     int x=sum-2*(A[i]-max(A[i-1],A[i+1]));
                  cout<<x<<endl;
  }else if(A[i]<A[i-1] && A[i]<A[i+1]){
     int x=sum-2*(min(A[i-1],A[i+1])-A[i]);
    cout<<x<<endl;
  }else
        cout<<sum<<endl;
            
  }
    return 0;
}