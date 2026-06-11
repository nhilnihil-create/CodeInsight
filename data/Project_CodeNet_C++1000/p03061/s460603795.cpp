#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
  if (y == 0)
    return x;
  
  return gcd(y, x%y);
} 

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0 ; i<N ; i++)
    cin >> A.at(i);
  
  vector<int> left(N, 0), right(N, 0);
  left.at(0) = 0;
  right.at(N-1) = 0;
  for (int i=0 ; i<N-1 ; i++)
    left.at(i+1) = gcd(left.at(i), A.at(i));
  for (int i=N-2 ; i>=0 ; i--)
    right.at(i) = gcd(right.at(i+1), A.at(i+1));
  
  vector<int> ans(N);
  for (int i=0 ; i<N ; i++)
    ans.at(i) = gcd(left.at(i), right.at(i));
  
  sort(ans.begin(), ans.end());
  
  cout << ans.at(N-1) << endl;
}