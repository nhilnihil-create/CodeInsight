#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int A,B;
  cin >> A >> B;

  int ans = max(A,B);

  if(A == B){
       cout << ans * 2  << endl;
  }else{
       cout << ans * 2 - 1 << endl;
  }

  return 0;
}
