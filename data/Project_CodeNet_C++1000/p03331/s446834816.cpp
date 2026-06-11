#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N ;
  int m = 10000;
  for(int i = 1; i < N ; i ++){
    int A = i;
    int B = N -i;
    int count_a = 0;
    int count_b = 0;
    while(A>0){
      count_a+= A % 10;
      A = A/10;
    }
    while(B> 0){
      count_b+= B % 10;
      B = B/10;
    }
    m = min(count_a + count_b, m);
  }
  cout << m << endl;
}