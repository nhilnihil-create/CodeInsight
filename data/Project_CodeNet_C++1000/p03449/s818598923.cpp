#include <bits/stdc++.h>
using namespace std;

int T(int i, int j, vector<vector<int>> a)
{
  int t = a.at(i).at(j);
  int up = 0;
  int left = 0;
  if(i==1 && j==1) return a.at(i).at(j);
  if(i!=1)
  {
    up += T(i-1,j,a);
  }
  if(j!=1)
  {
    left += T(i,j-1,a);
  }
  
  t += max(up,left);
  
  return t;
}


int main()
{
  int N;
  cin >> N;
  vector<vector<int>> a(3, vector<int>(101));
  
   for(int i=1; i<=N; i++)
  {
    cin >> a.at(1).at(i);
  }
  for(int i=1; i<=N ; i++)
  {
    cin >> a.at(2).at(i);
  }
  
  int t = T(2,N,a);
  
  cout << t << endl;
}
  
  