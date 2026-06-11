#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  int ans=0;
  for(int i=1;i<=N;++i){
    int sum=0;
    int temp=i;
    while(temp){
      sum+=temp%10;
      if(B<sum) break;
      temp/=10;
    }
    if(A<=sum && sum<=B) ans+=i;
  }

  cout << ans << endl;

  return 0;
}
