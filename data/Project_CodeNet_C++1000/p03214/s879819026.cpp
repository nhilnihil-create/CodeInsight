#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  int sum = 0;
  for(i = 0; i < n; i++)
  {
    cin >> a.at(i);
    sum += a.at(i);
    a.at(i) *= n;
  }
  int min = 10000;
  int check;
  for(i = 0; i < n; i++)
  {
    if(abs(a.at(i)-sum) < min)
    {
      check = i;
      min = abs(a.at(i)-sum);
    }
  }
  cout << check << endl;
}