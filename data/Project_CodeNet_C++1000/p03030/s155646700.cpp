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

using namespace std;
using P = pair<string,int>;

int main(){

  int N;
  cin >> N;

  vector<P> p1(N);
  vector<P> p2(N);

  string s;
  int p;

  for (int i = 0; i < N; i++) {
    cin >> s >> p;
    p1[i].first = s;
    p1[i].second = p*-1;
  }
  p2 = p1;
  sort(p1.begin(), p1.end());

  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      cnt++;
      if(p1[i].second == p2[j].second) break;
    }
    cout << cnt << endl;
  }

  return 0;
}