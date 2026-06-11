#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int A,B,C;
  cin >> A >> B >> C;

  if((B/A) >= C){
      cout << C << endl;
  }else{
      cout << (B/A) << endl;
  }
}
