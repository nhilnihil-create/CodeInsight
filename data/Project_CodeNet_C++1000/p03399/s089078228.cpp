#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  vector<int> vec;
  vec.push_back(a+c);
  vec.push_back(a+d);
  vec.push_back(b+c);
  vec.push_back(b+d);
  printf("%d\n",*min_element(vec.begin(),vec.end()));
  return 0;
}