#include <iostream>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int max_k = (n+1)/2;
  if(k>max_k)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  

  return 0;
}
