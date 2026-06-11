#include<iostream>
main(){
  std::string s;
  int d;
  std::cin>>s>>d;
  int n=s.size();
  std::string ans="";
  for(int i=0;i<n;++i){
    if(i%d==0)ans+=s[i];
  }
  std::cout<<ans<<std::endl;
}