#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m, c, cnt = 0;
  cin >> n >> m >> c;
  vector<int> b(m);
  
  for(int i=0; i<m; i++)
  {
    cin >> b[i];
  }
  for(int i=0; i<n; i++)
  {
    int score = c;
    for(int j=0; j<m; j++)
    {
      int a;
      cin >> a;
      score += a * b[j];
    }
    if(score > 0)
      cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}