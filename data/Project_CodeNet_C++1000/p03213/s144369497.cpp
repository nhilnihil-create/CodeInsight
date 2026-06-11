#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  int n = 0;
  cin >> n;
  vector<int> count(100);
  for(int i = 0;i < 100;i++)count[i] = 0;
  for(int i = 2;i <= n;i++){
    int now = i;
    for(int j = 2;j <= n;j++){
      while(now % j == 0){
        count[j]++;
        now /= j;
      }
    }
  }
  //for(int i = 0;i < 11;i++)cout << i << " " << count[i] << endl;
  int res = 0;
  for(int i = 0;i < 99;i++){
    if(count[i] < 4)continue;
    for(int j = i + 1;j < 100;j++){
      if(count[j] < 4 || i == j)continue;
      for(int k = 0;k < 100;k++){
        if(i != k && j != k && count[k] >= 2)res++;
      }
    }
  }
  for(int i = 0;i < 100;i++){
    if(count[i] < 24)continue;
    for(int j = 0;j < 100;j++){
      if(i != j && count[j] >= 2)res++;
    }
    //cout  << "!" << i << endl;
  }
  for(int i = 0;i < 100;i++){
    if(count[i] < 14)continue;
    for(int j = 0;j < 100;j++){
      if(i != j && count[j] >= 4)res++;
    }
  }
  for(int i = 0;i < 100;i++){
    if(count[i] >= 74)res++;
  }
  cout << res << endl;;
}