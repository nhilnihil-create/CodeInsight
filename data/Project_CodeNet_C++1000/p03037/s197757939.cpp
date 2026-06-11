#define _GLIBCXX_DEBUG
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, ans=0, max=0, min=100000;
  cin >> N >> M;
  int L[M], R[M];
  
  for(int i=0; i<M; i++){
			cin >> L[i] >> R[i];
	}

	for(int i=0; i<M; i++){
			if(L[i] >= max) max = L[i];
			if(R[i] <= min) min = R[i];
	}

	for(int i=1; i<=N; i++){
			if(max <= i && min >= i) ans++;
	}
  
  cout << ans << endl;
  
  
  return 0;
}
