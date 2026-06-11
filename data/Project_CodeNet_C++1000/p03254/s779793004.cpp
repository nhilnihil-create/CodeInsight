#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(void){
 
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
 
  sort((a).begin(), (a).end());
  int count = 0;
  for (int i=0; i<N-1; i++){
    x -= a[i];
    if(x >= 0) count++; 
    else break;
  }
  if(x - a[N-1] ==0) count++;
  
  cout << count << "\n";
}