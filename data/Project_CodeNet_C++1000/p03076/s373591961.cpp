#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
  int cnt = 0;
  vector<pair<int, int>> p(5);
  
  for(int i=0; i<5; i++)
  {
    int t;
    cin >> t;
    p[i] = {(10 - (t % 10)) % 10, t};
  }
  
  sort(p.begin(), p.end());
  for(int i=0; i<5; i++)
  {
    cnt += p[i].second;
    
    if(i == 4)
      break;
    
    while((cnt % 10) != 0)
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}