#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int64_t> a(n);
  for(int i=0;i<n;++i){
    cin>>a[i];
    if(a[i]%2==1){
      cout<<0<<endl;
      return 0;
    }
  }
  for(int j=0;;++j){
    int ok=0;
    for(int i=0;i<n;++i){
      if(a[i]%2==1){
        cout<<j<<endl;
        return 0;
      }
    }
    for(int i=0;i<n;++i)
      a[i]/=2;
  }
}