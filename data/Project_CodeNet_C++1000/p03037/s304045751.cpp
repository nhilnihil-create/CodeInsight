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
  int N,M,x,y;
  int L = 0,R = 1000000;
  cin >> N >> M;
  for(int i = 1;i <= M;i++){
    cin >> x >> y;
    L = max(L,x);
    R = min(R,y);
  }
  int count = R - L + 1;
  //cout << R << L << endl;
  count  = max(count,0);
  cout << count << endl;
}

/*int main(){
  vector<int> ID(100005);
  for(int i = 0;i < 100005;i++){
    ID.at(i) = 0;
  }
  int N,M,x,y;
  cin >> N >> M;
  cin >> x >> y;
  for(int i = x;i <= y;i++){
    ID.at(i) = 1;
  }
  for(int i = 1;i < M;i++){
    cin >> x >> y;
    for(int j = 1;j <= N;j++){
      if(ID.at(j) == 1){
        if(x <= j && j <= y){
          ID.at(j) = 1;
        }else{
          ID.at(j) = 0;
        }
      }
    }
  }
  int count = 0;
  for(int i = 1;i <= N;i++){
    if(ID.at(i) == 1){
      count++;
    }
  }
  cout << count << endl;
}*/
