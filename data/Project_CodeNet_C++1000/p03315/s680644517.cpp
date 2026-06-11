#include<iostream>
#include<string>
using namespace std;
int main()
{
    int k = 0;
  string s;
  cin >> s;
  for(int i = 0; i < 4; i++)
  {
      if(s[i] == '+')
        k++;
      if(s[i] == '-')
        k--;
  }
  cout << k;
  return 0;
}