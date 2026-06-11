#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

long long divnum(long long x){
  long long i=2;
  if(x < 2) return 1;
  else if(x == 2) return i;
  if(x%2 == 0) i+=2;
  if(x == 4) return 3;
  for(long long j = 3; j*j <= x; j += 1){
    if(x%j == 0){
      if(x == j) i++;
      else{
        i+=2;
        if(x == j*j) i--;
      }
    }
  }
  return i;
}

int main() {
  long long N;
  int ans = 0;

  cin >> N;

    for(long long  i = 1; i<= N; i++){
        long long  tmp = divnum(i);
        if(tmp == 8 && i%2 == 1) ans++;
    }
    cout << ans << endl;
}
