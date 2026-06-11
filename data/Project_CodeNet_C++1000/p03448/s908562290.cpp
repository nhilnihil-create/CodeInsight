#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> vec;
  int i, j, k, x, sum, counter = 0;
  while(cin>>x) {
  	vec.push_back(x); 
  }
  sum = vec.back();
  vec.pop_back();
  for(i = 0; i <= vec[0]; i++) {
    for(j = 0; j <= vec[1]; j++) {
      for(k = 0; k <= vec[2]; k++) {
        x = 500 * i + 100 * j + 50 * k;
		if (sum == x)  {
          counter++;
        }
      }  
    }  
  }
  
  printf("%d", counter);
  return 0;
}