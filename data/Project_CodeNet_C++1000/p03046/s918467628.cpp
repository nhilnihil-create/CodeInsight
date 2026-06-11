#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

// int max: 2 x 10^9, long long max: 9 x 10^18

using namespace std;

int main()
{
  int m;
  long long k;
  cin >> m >> k;
  
  long long repeat = 1 << (m+1);
  
  if(k == 0){
    for(long long i=0; i< repeat; i++){
      cout << (long long)(i / 2) << " ";
    }
    cout << "\n";
  }else if(k > (1 << m)){
    cout << -1;
  }else{
    long long result = 0;
    repeat = 1 << m;
    for(long long i=0; i<repeat; i++){
      if(i != k){
        result = result ^ i;
      }
    }
    if(result == k){
      cout << k << " ";
      repeat = 1 << m;
      for(long long i=0; i<repeat; i++){
        if(i != k){
          cout << i << " ";
        }
      }
      cout << k;
      for(long long i=0; i<repeat; i++){
        if((repeat - i - 1) != k){
        	cout << " " << (repeat - i - 1);
        }
      }
    }else{
      cout << -1;
    }
  }

  return 0;
}