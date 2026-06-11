#include <iostream>
#include <string>

int main(){
  std::string s;
  long long ans = 0, j = 0;
  
  std::cin>>s;
  
  for(int k = 0; (k = s.find("BC", k)) != std::string::npos;){
    s.replace(k, 2, "D");
  }
  
  for(int i = 0; 0 <= i && i < s.length(); i++){
    if(s[i] == 'A')j++;
    else if(s[i] == 'D')ans += j;
    else j = 0;
  }
  
  std::cout<<ans;
  
  return 0;
}
