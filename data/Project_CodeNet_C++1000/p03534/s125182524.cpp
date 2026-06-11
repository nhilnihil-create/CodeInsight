#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int len;
  std::vector<int> a(3);
  std::cin >> s;
  len=s.length();
  if(len==1){
    std::cout << "YES" << std::endl;
  }else if(len==2){
    if(s.at(0)!=s.at(1))std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
  }else{
    for (int i = 0; i < len; i++) {
      /* code */
      if(s[i]=='a')a.at(0)++;
      if(s[i]=='b')a.at(1)++;
      if(s[i]=='c')a.at(2)++;
    }
    sort(a.begin(),a.end());
    if(abs(a.at(0)-a.at(2))>=2)std::cout << "NO" << std::endl;
    else std::cout << "YES" << std::endl;
  }
  
  
}
