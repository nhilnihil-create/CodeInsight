#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string abcd;
  cin >> abcd;

  vector<int> n(4);
  rep(i,4) n[i] = abcd[i] - '0';

  if(n[0]+n[1]+n[2]+n[3]==7) printf("%d+%d+%d+%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]+n[1]+n[2]-n[3]==7) printf("%d+%d+%d-%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]+n[1]-n[2]+n[3]==7) printf("%d+%d-%d+%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]+n[1]-n[2]-n[3]==7) printf("%d+%d-%d-%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]-n[1]+n[2]+n[3]==7) printf("%d-%d+%d+%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]-n[1]+n[2]-n[3]==7) printf("%d-%d+%d-%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]-n[1]-n[2]+n[3]==7) printf("%d-%d-%d+%d=7",n[0],n[1],n[2],n[3]);
  else if(n[0]-n[1]-n[2]-n[3]==7) printf("%d-%d-%d-%d=7",n[0],n[1],n[2],n[3]);

  return 0;
}