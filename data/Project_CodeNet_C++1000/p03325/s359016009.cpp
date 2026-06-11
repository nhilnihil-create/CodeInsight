#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  int count=0;
  int ans=0;
  vector<long long>a(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>a[i];
    while(a[i]%2==0){
    
      a[i]/=2;
      count++;
    }
    ans+=count;
    count=0;
  }
  cout<<ans;
}