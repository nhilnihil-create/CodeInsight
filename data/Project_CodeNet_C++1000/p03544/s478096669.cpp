#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  //

  long long L[100];
  L[0] = 2;
  L[1] = 1;
  
  rep(i, N-1){
    L[i+2] = L[i+1]+L[i];
  }

  cout << L[N] << endl;

  return 0;
}
