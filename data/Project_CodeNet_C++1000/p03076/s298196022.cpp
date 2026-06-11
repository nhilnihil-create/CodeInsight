#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  int ans = 0;

  vector<P> p(5);
  p[0].first  = A%10;
  p[0].second = A;
  p[1].first  = B%10;
  p[1].second = B;
  p[2].first  = C%10;
  p[2].second = C;
  p[3].first  = D%10;
  p[3].second = D;
  p[4].first  = E%10;
  p[4].second = E;
  sort(p.begin(), p.end());

  bool flag = false;
  for (int i = 0; i < 5; i++) {
    if(p[i].first == 0){
      ans += p[i].second;
    }else{
      if(flag == false){
        ans += p[i].second;
        flag = true;
      }else{
        ans += (p[i].second/10 + 1)*10;
      }
    }
    // cout << p[i].first << " -> " << p[i].second << endl;
  }

  cout << ans << endl;

  return 0;
}