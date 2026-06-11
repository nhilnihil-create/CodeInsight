 #include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
  string s;
  int k = 0;
  cin >> s;
  if(s[0] == 'o')
    k++;
  if(s[1] == 'o')
    k++;
  if(s[2] == 'o')
    k++;
  cout << 700 + 100 * k;
  return 0;
}
