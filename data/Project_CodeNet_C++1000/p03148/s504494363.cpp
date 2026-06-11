#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>
#include <stack>
#include <unordered_set>

using namespace std;

int main(){

  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> dt(N);

  int t, d;
  for(int i = 0; i < N; i++){
    cin >> t >> d;
    dt[i] = make_pair(d, t);
  }

  sort(dt.begin(), dt.end(), greater<pair<int, int>>());

  unordered_set<int> used;
  stack<int> replaceStack;

  long long ans = -1;
  long long tempSum = 0;
  long long typeCnt = 0;
  for(int i = 0; i < K; i++){
    auto temp = dt[i];
    if(used.find(temp.second) == used.end()){
      used.insert(temp.second);
      tempSum += temp.first;
      tempSum -= typeCnt * typeCnt;
      typeCnt++;
      tempSum += typeCnt * typeCnt;
    }
    else{
      replaceStack.push(temp.first);
      tempSum += temp.first;
    }
  }

  ans = tempSum;

  for(int i = K; i < N; i++){
    auto temp = dt[i];
    if(used.find(temp.second) == used.end()){
      if(!replaceStack.empty()){
	int replaceScore = replaceStack.top();
	replaceStack.pop();
	used.insert(temp.second);
	tempSum -= replaceScore;
	tempSum += temp.first;
	tempSum -= typeCnt * typeCnt;
	typeCnt++;
	tempSum += typeCnt * typeCnt;
	ans = max(ans, tempSum);
      }
      else{
	break;
      }
    }
    else{
      continue;
    }
  }

  cout << ans << endl;

  return 0;
}
