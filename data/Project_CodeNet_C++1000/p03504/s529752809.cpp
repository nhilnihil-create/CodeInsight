#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define ALL(a) (a).begin(), (a).end()
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int s[100000],t[100000],c[100000]; 
int sm[200002]; 
int tt[200002]; 

int main(void){
  int N, C;
  scanf("%d%d",&N,&C);
 
  rep(i, N) scanf("%d%d%d",&s[i],&t[i],&c[i]);
  rep_s(i, 1, C+1){
    for(int j=0;j<200002;j++)tt[j]=0; 
    for(int j=0;j<N;j++)if(c[j]==i)tt[s[j]*2-1]++,tt[t[j]*2]--; 
    for(int j=1;j<200002;j++)tt[j]+=tt[j-1]; 
    for(int j=0;j<200002;j++)if(tt[j]>0)sm[j]++;
  }
  int mx = 0;
  for(int j=0;j<200002;j++)if(mx<sm[j])mx=sm[j]; 
  printf("%d\n",mx);
}
