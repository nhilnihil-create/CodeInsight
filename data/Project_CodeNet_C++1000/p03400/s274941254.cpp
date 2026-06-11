#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n , d , rem;
  cin >> n >> d >> rem;
  for(int i=0; i<n; i++)
  {
      int v ;
      cin >> v;
      for(int j=0;   ; j++)
      {
          if(v*j+1<=d)rem++;
          else break;
      }
  }
  cout << rem << endl;
}
