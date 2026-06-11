#include <iostream>
#include <set>

using namespace std;

int main(){
  int A, B, K;
  cin >> A >> B >> K;

  set<int> s;
  
  for(int i=A; i<A+K; i++)
    if(A <= i && i <= B)
      s.insert(i);
  for(int i=B-K+1; i<=B; i++)
    if(A <= i && i <= B)
       s.insert(i);

  for(auto a : s)
    cout << a << endl;
  
  return 0;
}
