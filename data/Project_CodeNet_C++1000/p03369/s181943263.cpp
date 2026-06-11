#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  int count = 0;
  string s;
  cin >> s;
  
  for(int i = 0; i < 3; i++)
  {
    if(s[i] == 'o')
    {
      count++;
    }
  }
  
  cout << 700 + (100*count);
}