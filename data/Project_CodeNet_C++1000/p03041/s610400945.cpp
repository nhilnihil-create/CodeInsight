#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,k;
  string s;
  cin>>n>>k;
  cin>>s;
  s[k-1]+=32;
  cout<<s<<"\n";
  return 0;
}