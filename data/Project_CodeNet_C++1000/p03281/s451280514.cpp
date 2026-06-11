#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, cnt = 0, ans = 0;
  cin >> N;

  for(int i = 1; i <= N; i++){
    if(i % 2 == 1){
      for(int j = 1; j <= i; j++){
	if(i % j == 0)
	  cnt++;
      }
      //printf("%d:%d\n",i,cnt);
      if(cnt == 8)
	ans++;
      cnt = 0;
    }
  }

  cout << ans << "\n";
  return 0;
}	  