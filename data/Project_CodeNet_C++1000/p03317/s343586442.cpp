#include <iostream>
#include <string>
#include <vector>

#include <climits>

#define DEBUG if(false)

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N, 0);
  int which_1 = -1;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(A[i] == 1){
      which_1 = i;
    }
  }
  int K_left = (which_1-K+1>0)?which_1-K+1:0; //デフォルト
  DEBUG printf("K_left : %d\n", K_left);
  int minimum = INT_MAX;
  for(int i = 0; i < K; i++){
    int l_left = K_left + i;
    int r_left = l_left + K-1;
    if(r_left > N-1) break;
    DEBUG printf("l_left : %d\n", l_left);
    DEBUG printf("r_left : %d\n", r_left);

    int count = 1;
    count += (l_left + K-2)/(K-1);
    count += (N-1 - r_left + K-2)/(K-1);
    DEBUG printf("%d\n", count);
    if(minimum > count){
      minimum = count;
    }
  }
  cout << minimum << endl;

  return 0;
}
