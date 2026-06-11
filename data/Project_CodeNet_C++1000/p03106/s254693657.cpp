#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(void){
  int A, B, K;
  cin >> A >> B >> K;
  int N = max(A,B);
  int ans[N];
  int count = 0;
  map<int, int> D;
  for (int i=1;i<=N;i++){
    if((A%i)==0 && (B%i)==0){
      count++;
      D[count] = i;
    }
  }
  cout << D[count-K+1] << endl;
  return 0;
}