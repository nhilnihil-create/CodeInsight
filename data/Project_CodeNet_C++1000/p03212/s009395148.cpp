#include <bits/stdc++.h>
using namespace std;

map<int, int> sftNums;

void addSftNums(vector<int> work) {
  int scale=0;
  int sftNum=0;
  map<int, int> sftMap;
  for (auto w: work) {
    if (w==0) continue;
    sftNum+=w*pow(10,scale++);
    sftMap[w]++;
  }

  if (sftMap[7]>0&&sftMap[5]>0&&sftMap[3]>0){
    if (sftNum!=0){
      sftNums[sftNum]++;
    }
  }
  return;
}

void dfs(vector<int> work, int num, int idx){
  work.push_back(num);
  if(idx==9) {
    addSftNums(work);
    return;
  }
  int nums[4] = {0,3,5,7};
  for (int i = 0; i < 4; i++) {
    dfs(work, nums[i], idx+1);
  }
  return;
}

int main() {
  int N;
  cin >> N;

  vector<int> blank;
  dfs(blank, 0, 0);

  int ans = 0;
  for (auto sftNum: sftNums){
    if (sftNum.second ==0 ) continue;

    if (sftNum.first > N) break;

    ans++;
  }

  cout << ans << endl;
  return 0;
}