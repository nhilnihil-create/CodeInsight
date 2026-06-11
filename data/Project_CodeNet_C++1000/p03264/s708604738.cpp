#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int k;
  cin>>k;
  cout<<(k/2)*((k/2)+(k%2))<<"\n";
  return 0;
}