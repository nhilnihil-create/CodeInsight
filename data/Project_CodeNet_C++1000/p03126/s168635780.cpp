#include<iostream>
#include<vector>
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<int> vote(m, 0);
  
  int k;
  int tmp;
  rep(i, n)
  {
    cin >> k;
    rep(j, k)
    {
      cin >> tmp;
      vote.at(-- tmp) ++;
    }
  }
  
  int count = 0;
  rep(i, m)
  {
    if (vote.at(i) >= n) count ++;
  }
  
  cout << count;
  return 0;
}