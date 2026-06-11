#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  
  vector<int> cnt(N);
  for(int i = 1;i < N;i++) cnt.at(i) = cnt.at(i-1) + (S.at(i-1) == 'A' && S.at(i) == 'C'); 
  
  for(int i = 0;i < Q;i++){
    int l, r;
    cin >> l >> r;
    
    cout << cnt.at(r-1) - cnt.at(l-1) << endl;
  }
  
  return 0;
}