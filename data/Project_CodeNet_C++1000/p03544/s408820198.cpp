#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int64_t> a(n+1);
  a[0]=2;a[1]=1;
  if(n>=2)
    for(int i=2;i<n+1;++i){
      a[i]=a[i-1]+a[i-2];
    }
  cout<<a[n]<<endl;
}