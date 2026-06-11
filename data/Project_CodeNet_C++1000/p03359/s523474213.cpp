#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a, b, cnt = 0;
  cin >> a >> b;
  for(int i = 1; i <= a; i++){
    if(i != a){
      for(int j = 1; j <= 31; j++){
	if(i == j)
	  cnt++;
      }
    }
    else{
      for(int j = 1; j <= b; j++){
        if(i == j)
	  cnt++;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
