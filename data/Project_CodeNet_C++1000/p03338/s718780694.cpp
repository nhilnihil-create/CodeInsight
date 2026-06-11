#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N, cnt, ans = 0;
  string s;
  cin >> N >> s;
  rep(i, N-1){ // i番目とi+1番目の間できる
    vector<int> a(26, 0);
    vector<int> b(26, 0);
    rep(j, i+1){
      a[s[j]-'a']++;
    }
    for(int j=i+1; j < N; j++){
      b[s[j]-'a']++;
    }
    cnt = 0;
    rep(j, 26){
      if(a[j] > 0 && b[j] > 0) cnt++;
    }
    ans = max(ans, cnt);
  }
  print(ans);

}
