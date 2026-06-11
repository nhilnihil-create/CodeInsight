#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, i;
	string S;
  	
    cin >> N;
  
  for (i = 0; i < N; ++i)
  {
    cin >> S;
    if (S == "Y")
    {
      cout << "Four" << endl;
      break;
    }
    if (i == N - 1 && S != "Y")
    {
      cout << "Three" << endl;
    }
  }
}