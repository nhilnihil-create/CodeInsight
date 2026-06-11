#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t s;
  cin>>s;
vector<int64_t> vec(87);
 vec.at(0)=2;
  vec.at(1)=1;
  for(int64_t i=2;i<87;i++){
  vec.at(i)=vec.at(i-1)+vec.at(i-2);
  }
  cout<<vec.at(s)<<endl;
}