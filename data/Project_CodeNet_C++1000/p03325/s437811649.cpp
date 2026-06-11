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
using P = pair<int,int>;

int main(){

  int N, a;
  cin >> N;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  bool flag = true;
  int check = 0;
  int cnt = 0;

  while (flag == true){
    if(flag == false) break;

    bool first = true;
    for (int i = 0; i < N; i++) {
      if(vec.at(i)%2 != 0){
        vec.at(i) = vec.at(i)*3;
      } else {
        if(first == true){
          vec.at(i) = vec.at(i)/2;
          first = false;
        } else {
          vec.at(i) = vec.at(i)*3;
        }
      }
    }
    if(first == true) break;
    ans++;
  }

  cout << ans << endl;


  return 0;
}