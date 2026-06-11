#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m, cnt = 0;
  cin >> n >> m;
  
  vector<bool> res(m);
  for(int i=0; i<m; i++) res[i] = true;
  
  for(int i=0; i<n; i++)
  {
    vector<bool> res_tmp(m);
    for(int j=0; j<m; j++) res_tmp[j] = false;
    
    int k;
    cin >> k;
    
    for(int j=0; j<k; j++)
    {
      int a;
      cin >> a;
      res_tmp[a-1] = true;
    }
    
    for(int j=0; j<m; j++)
    {
      if(res_tmp[j] == false)
        res[j] = false;
    }
  }
  
  for(int i=0; i<m; i++)
  {
    if(res[i] == true)
      cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}