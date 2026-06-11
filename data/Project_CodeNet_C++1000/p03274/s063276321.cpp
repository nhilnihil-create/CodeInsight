#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  int mini = 1001001001;
  for(int i = 0; i < n - k + 1; i++){
    if(x[i] < 0 && x[i + k - 1] < 0){
      mini = min(mini, -x[i]);
    }else if(x[i] < 0 && x[i + k - 1] >= 0){
      mini = min({mini, -x[i] * 2 + x[i + k - 1], x[i + k - 1] * 2 - x[i]});
    }else{
      mini = min(mini, x[i + k - 1]);
    }
  }
  cout << mini << endl;
  return 0;
}