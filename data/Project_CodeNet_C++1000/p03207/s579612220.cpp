#include <iostream>
using namespace std;
int p[10000];
int main()
{
  int n,max=0,cijena=0,kraj;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> p[i];
    cijena=cijena+p[i];
    if (p[i]>max)
      max=p[i];
    kraj=cijena-(max/2);
  }
  cout << kraj;
}