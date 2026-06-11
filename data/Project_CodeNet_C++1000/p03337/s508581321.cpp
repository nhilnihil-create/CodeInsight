#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b; cin>>a>>b;
  vector<int> vec;
  vec.push_back(a+b);
  vec.push_back(a-b);
  vec.push_back(a*b);
  printf("%d\n",*max_element(vec.begin(),vec.end()));
  return 0;
}
