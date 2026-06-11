#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  cin >> N;

  vector<int> P(N),Q(N);
  for(int i = 0;i < N;i++) {
    cin >> P.at(i);
    Q.at(P.at(i)-1) = i;
  }

  int M = 0,num = 1;
  for(int i = 0;i < N-1;i++) {
    if(Q.at(i) < Q.at(i+1)) num++;
    else {
      M = max(M,num);
      num = 1;
    }
  }

  M = max(M,num);
  cout << N-M << endl;


}
