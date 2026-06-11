#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long long a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  int num = 0;
  while(true)
  {
    bool flag = false;
    for(int i = 0; i < n; ++i)
    {
      if(a[i] % 2 == 0) a[i] /= 2;
      else flag = true;
    }
    if(flag) break;
    num++;
  }
  
  cout << num << endl;
}
