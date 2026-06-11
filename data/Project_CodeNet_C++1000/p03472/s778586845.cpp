#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  cin >> N >> H;
  vector<int>A(N);
  vector<int>B(N);
  for(int i=0; i<N; i++)cin >> A.at(i) >> B.at(i);
  
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  
  int count =0;
  for(int i=N-1; i>=0; i--){
    if(A.at(N-1)<B.at(i)){
      count ++;
      H -= B.at(i);
        if(H<=0)break;
    }
    else break;
  }
  
  if(H>0){
    count += (H-1)/A.at(N-1)+1;
  }
  
  cout << count << endl;
}