#include <bits/stdc++.h>
using namespace std;


int main()
{
  int N, count = 0;
  cin >> N;

  for (int i = 0; i < 27; i++)
  {
    for (int k = 0; k < 15; k++)
    {
      if(N == 4 * i + 7 * k){
        ++count;
      }
    }
  }
  if(count > 0){
    cout << "Yes" << endl;
  }else if(count == 0){
    cout << "No" << endl;
  }
}
