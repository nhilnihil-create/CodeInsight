#include <bits/stdc++.h>
using namespace std;

int main(void){
  long long N;
  cin >> N;
  for(long long i = 1; i <= 3501; i++){
   for(long long j = 1; j <= 3501; j++){
     long long up = N * i * j;
     long long down = (long long) 4 * i * j - N * i - N * j;
     if(down == 0)continue;
     if(up % down != 0) continue; 
     if(up / down > 0 && up / down < 3501){
       cout << i << " " << j << " " << up / down;
       return 0;
     }
   }
    
  }
  return 0;
}