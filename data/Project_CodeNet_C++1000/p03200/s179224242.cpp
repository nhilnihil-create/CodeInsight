#include<iostream>
#define ll long long

int main(){
std::string s;
  std::cin >> s;
  ll t=0,ind=0;
  for(int i=0;i<(ll)s.length();i++){
    if(s[i]=='W'){
        t+=i-ind;
        ind++;
    }
}
  std::cout << t << std::endl;
return 0;
}
