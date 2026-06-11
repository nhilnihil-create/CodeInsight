#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  int lw = A + B;
  int rw = C + D;
  if (lw > rw)
  {
    printf("Left");
  }
  else if (lw < rw)
  {
    printf("Right");
  }
  else
  {
    printf("Balanced");
  }
}
