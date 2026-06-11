#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N ;
  vector<int> A(N);
  for (int i;i<N;i++) {
    cin >> A[i];
  }
  int s=0;
  bool a=false;
  while(true){
    for(int i=0;i<N;i++){
      if(A[i]%2!=0) {a=true;break;}
      A[i]/=2;
    }
    if(a) break;
    s++;
  }
  cout<<s<<endl;
}
