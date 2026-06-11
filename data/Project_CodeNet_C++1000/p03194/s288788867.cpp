#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;


int main(){
  long long int n, p, a, cnt=0, ans=1;
  cin >> p >> n;
  a=2;
  while(n>=a*a){
    if(n%a==0){
      cnt++;
      n/=a;
      if(cnt==p){
        ans*=a;
        cnt=0;
      }
    }
    else{
      a++;
      cnt=0;
    }
  }
  cnt++;
  if(cnt==p){
    ans*=n;
  }
  cout << ans << endl;
  return 0;
}
