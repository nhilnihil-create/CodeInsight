#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, X, x;
  vector<int> m;
  cin >> N >> X;
  
  for(int i=0; i<N; i++){
    cin >> x;
    m.push_back(x);
  }
  
  sort(m.begin(),m.end());
  int sum = accumulate(m.begin(), m.end(), 0);
  X -= sum;
  if(X<0){
    cout << 0 << endl;
    return 0;
  }
  
  cout << X/m[0] + N << endl;
  return 0;
  
  
  
}