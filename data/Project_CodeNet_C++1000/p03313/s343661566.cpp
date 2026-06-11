#include<bits/stdc++.h>
using namespace std;
int N;
int A[1<<18];
int mv1[1<<18];
int mv2[1<<18];
int ans[1<<18];
void upd(int a, int b)
{
  set<pair<int, int> > S;
  S.emplace(A[mv1[a]], mv1[a]);
  S.emplace(A[mv1[b]], mv1[b]);
  S.emplace(A[mv2[a]], mv2[a]);
  S.emplace(A[mv2[b]], mv2[b]);
  auto it = S.rbegin();
  auto it2 = it; ++it2;
  mv1[a] = it->second; mv2[a] = it2->second;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<(1<<N); ++i)
  {
    scanf("%d", A+i);
    mv1[i] = i;
    mv2[i] = i;
  }
  for(int i=1; i<(1<<N); ++i)
  {
    for(int j=0; j<N; ++j)
      if(i&(1<<j)) upd(i, i-(1<<j));
    ans[i] = max(ans[i-1], A[mv1[i]]+A[mv2[i]]);
    printf("%d\n", ans[i]);
  }
  return 0;
}