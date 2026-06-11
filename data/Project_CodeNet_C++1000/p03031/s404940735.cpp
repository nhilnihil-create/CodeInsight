#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long
#define all(v) v.begin(),v.end()
using namespace std;
int main () {
  int N,M ;cin >> N >> M;
  vector<int> k(M);
  vector<vector<int>> A(M);
  rep(i,M){
    cin >> k[i];
    rep(j,k[i]){
      int a; cin >>a;
      A[i].push_back(a-1);
    }
  }
  vector<int> p(M);
  rep(i,M) cin >> p[i];
  int count=0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<10> s(tmp);  // 最大10個なので10ビットのビット列として扱う
    bool ans=true;
    rep(i,M){ 
      int sum = 0;
      for (int j = 0; j < k[i]; j++) if(s.test(A[i][j])) sum++;
      if (sum%2 != p[i])ans=false;
    }
    if(ans)count++;
  }
  cout <<count<<endl;
}