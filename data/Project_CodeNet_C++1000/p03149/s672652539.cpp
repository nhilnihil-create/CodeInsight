#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<string, int> mp = {{"1", 0}, {"9", 0}, {"7", 0}, {"4", 0}};
  string N;
  bool ans = true;
  
  for(int i = 0; i < 4; i++)
  {
    cin >> N;
    auto itr = mp.find(N);
    if(itr != mp.end())
      mp.at(N)++;
  }
  
  map<string, int>::iterator it;
  for(it = mp.begin(); it != mp.end(); it++)
  {
    if(it->second != 1)
    {
      ans = false;
      break;
    }
  }
  
  if(ans)
    cout << "YES" <<endl;
  else
    cout << "NO" << endl;
}