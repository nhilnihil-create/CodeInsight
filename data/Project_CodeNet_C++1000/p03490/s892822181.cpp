#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  string S;
  int X, Y;

  cin >> S;
  cin >> X >> Y;

  vector< int > compress;
  compress.emplace_back(0);
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == 'T') compress.emplace_back(0);
    else compress.back()++;
  }

  bitset< 16001 > latte, malta;
  latte[8000 + compress.front()] = malta[8000] = true;
  for(int i = 1; i < compress.size(); i++) {
    if(i % 2 == 0) latte = (latte << compress[i]) | (latte >> compress[i]);
    else malta = (malta << compress[i]) | (malta >> compress[i]);
  }

  if(latte[8000 + X] && malta[8000 + Y]) puts("Yes");
  else puts("No");
}