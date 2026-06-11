#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  double kei,kpt;
  int now;
  for(int i = 1;i <= N;i++){
    now = i;
    kpt = 1.0/N;
    while(now < K){
      now = now * 2;
      kpt = 0.5 * kpt;
    }
    kei += kpt;
    //cout << kpt << endl;
  }
  cout << fixed << setprecision(12) << kei << endl;
}
