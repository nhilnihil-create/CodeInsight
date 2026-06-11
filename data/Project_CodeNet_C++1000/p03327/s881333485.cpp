#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main(){
  int N;scanf("%d",&N);
  printf(N <= 999 ? "ABC\n":"ABD\n");
}