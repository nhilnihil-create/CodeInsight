#include<iostream>
#include<algorithm>
using namespace std;
 
int main(){
  int A,B;
  cin >> A >> B;
  
  if(A < B) swap(A , B);
  int ans = max(A + A - 1 , A + B);
  
  cout << ans << endl;
}