#include <bits/stdc++.h>
using namespace std;
 
int main() {	//N個の整数から連続するK個を選ぶ
  int N, K, count = 0;
  
  cin >> N >> K;
  
  for (int i=0; i<N-K+1; i++)
    count++;
  
  cout << count << endl;
  
}