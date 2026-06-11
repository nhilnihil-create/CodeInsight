#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  int h, w;cin>>h>>w;
  int a, b;cin>>a>>b;
  cout<<h*w-a*w-b*(h-a)<<endl;
}