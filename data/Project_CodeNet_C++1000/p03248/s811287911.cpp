#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin>>s;
  s="0"+s;

  if(s==string(s.rbegin(), s.rend())&&s[1]=='1') {
    int r=1;
    for(int i=2; i<s.size(); i++){
      printf("%d %d\n",r,i);
      if(s[i-1]=='1')r=i;
    }
  }else{
    puts("-1");
  }
}