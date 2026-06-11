#include <iostream>

using namespace std;

int main()
{
  int n,x,y;
  cin >> n >> x >> y;
  int ans=0;
  for(int i=0; i<n; ++i)
  {
    int u,v;
    cin >> u >> v;
    if (u>=x && v>=y) ans++; 
  }
  cout << ans;
  return 0;
}