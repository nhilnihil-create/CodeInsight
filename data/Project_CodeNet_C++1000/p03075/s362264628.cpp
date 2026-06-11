#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int a,b,c,d,e,k;
  cin >> a >> b >> c >> d >> e >> k;
  
  if(e - a <= k){
      cout << "Yay!" << endl;
  }else{
      cout << ":(" << endl;
  }

  return 0;
}
