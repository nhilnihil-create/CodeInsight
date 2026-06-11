 //#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

int main(){
  int H, W; cin >> H >> W;
  int A[H][W];
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> A[i][j];
    }
  }
    //keep moving until the elements are even or or has reached the bottom last corner
  vector <Pii> ans1, ans2;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (A[i][j] % 2 == 0) continue;
      else{
        if (j < W - 1){
          ans1.push_back(make_pair(i, j));
          ans2.push_back(make_pair(i, j + 1));
          A[i][j]--; A[i][j + 1]++;
        }else{
          if (i == H - 1) continue;
          A[i][j]--; A[i + 1][j]++;
          ans1.push_back(make_pair(i, j));
          ans2.push_back(make_pair(i + 1, j));
        }
      }
    }
  }
  
  cout << ans1.size() << endl;
  for (int i = 0; i < ans1.size(); i++){
    cout << ans1[i].first + 1 << " " << ans1[i].second + 1 << " ";
    cout << ans2[i].first + 1 << " " << ans2[i].second + 1 << endl;
  }
  
  
  return 0;
}
