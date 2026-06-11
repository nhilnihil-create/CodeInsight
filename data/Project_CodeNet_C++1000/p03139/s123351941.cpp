#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  
  // 最大
  cout << min(A, B) << " ";
  
  // 最小
  if(((A + B) - N) <= 0)
    cout << "0" << endl;
  else
    cout << (A + B) - N << endl;
}