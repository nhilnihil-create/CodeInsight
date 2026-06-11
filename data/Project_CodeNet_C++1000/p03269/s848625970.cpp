#include<bits/stdc++.h>
using namespace std;

int main()
{

  vector<tuple<int, int, int> > ans;
  for(int i=1; i<=18; ++i)
  {
    ans.emplace_back(i, i+1, 0);
    ans.emplace_back(i, i+1, 1<<(i-1));
  }
  
  int L; scanf("%d", &L); int rL = L;
  int ii = 19;
  while(L)
  {
    if(L >= (1<<(ii-1)))
    {
      ans.emplace_back(ii, 20, rL-L);
      L -= 1 << (ii-1);
    }
    else --ii;
  }
  printf("20 %d\n", (int)ans.size());
  for(auto x: ans)
  {
    int a, b, c;
    tie(a,b,c) = x;
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}