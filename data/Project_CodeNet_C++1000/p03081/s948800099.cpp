//#include <bits/stdc++.h>
#include <iostream>
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

using namespace std;

typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const long long INF = 1e18;
const double PI = 2 * asin(1);


int main(){
  int N, Q; cin >> N >> Q;
  string S; cin >> S;

  vector <char> T(Q), D(Q);
  for (int i = 0; i < Q; i++){
    cin >> T[i] >> D[i];
  }

  bool flagL = false, flagR = false;

  int num = N - 1;
  for (int i = 0; i < Q; i++){
    if (S[num] == T[i]){
      if (D[i] == 'L') num--;
      else num++;
    }
    if (num >= N){
      flagR = true; break;
    }else if (num < 0){
      cout << 0 << endl;
      return 0;
    }
  }
  num = 0;
  for (int i = 0; i < Q; i++){
    if (S[num] == T[i]){
      if (D[i] == 'L') num--;
      else num++;
    }
    if (num < 0) {
      flagL = true; break;
    }else if (num >= N){
      cout << 0 << endl;
      return 0;
    }
  }
  
  int ansL = 0, ansR = N;

  int L = 0, R = N - 1;
  while (flagL == true){
    const int start = (L + R) / 2;
    int now = start;
    bool flag = true;
    for (int i = 0; i < Q; i++){
      if (T[i] == S[now]){
        if (D[i] == 'L') now--;
        else now++;
      }
      if (now < 0){
        flag = false; break;
      }else if (now >= N){
        break;
      }
    }

    if (flag == true) R = start;
    else L = start;

    if (start == (L + R) / 2){
      if (flagR == false){
        cout << N - R << endl;
        return 0;
      }
      ansL = R; break;
    }
  }

  L = 0, R = N - 1;
  while (flagR == true){
    const int start = (L + R) / 2;
    int now = start;
    bool flag = true;
    for (int i = 0; i < Q; i++){
      if (T[i] == S[now]){
        if (D[i] == 'L') now--;
        else now++;
      }
      if (now < 0){
        break;
      }else if (now >= N){
        flag = false; break;
      }
    }

    if (flag == true) L = start;
    else R = start;

    if (start == (L + R) / 2){
      if (flagL == false){
        cout << L + 1 << endl;
        return 0;
      }
      
      ansR = L; break;
    }
  }
  cout << ansR - ansL + 1 << endl;

  return 0;
}
