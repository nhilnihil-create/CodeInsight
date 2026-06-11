#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

char S[304][304];

int main(){
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++){
    std::string s;
    std::cin >> s;
    for (int j=0; j<N; j++){
      S[i][j]=s[j];
    }
  }
  int ans = 0;
  for (int d=-N+1; d<=N-1; d++){
    //printf("d=%d\n", d);
    bool ok=true;
    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
	int I = j+d;
	if (I<0) I+=N;
	if (I>=N) I-=N;
	int J = i-d;
	if (J<0) J+=N;
	if (J>=N) J-=N;
	if (S[i][j]!=S[I][J]) {
	  ok=false;
	  break;
	}
      }
    }
    if (ok){
      //printf("+=%d\n", N-abs(d));
      ans += N-abs(d);
    }
  }
  std::cout << ans << std::endl;
		      
  return 0;
}
