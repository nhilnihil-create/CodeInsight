#include<iostream>
#include<vector>

int main(){
  int n,ans=0;
  std::cin>>n;
  std::vector<int>a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    while(a[i]%2==0){
      ans++;
      a[i]/=2;
    }
  }
  std::cout<<ans<<std::endl;
  return 0;
}