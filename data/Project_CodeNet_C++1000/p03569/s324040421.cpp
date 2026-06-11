#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  string str;
  cin >> str;
  string checkStr = "";
  rep(i, str.length()){
    if(str[i] != 'x') checkStr = checkStr + str[i];
  }
  bool kaibun = true;
  rep(i, checkStr.length()/2){
    if(checkStr[i] != checkStr[checkStr.length()-1-i]){
      kaibun = false;
      break;
    }
  }
  if(!kaibun){
    cout << -1 << endl;
    return 0;
  }
  int vecLength;
  if(checkStr.length() % 2 == 0) vecLength = checkStr.length() / 2;
  else vecLength = checkStr.length() / 2 + 1; 
  vector<int> front(vecLength, 0);
  vector<int> back(vecLength, 0);
  deque<char> que;
  rep(i, str.length()) que.push_back(str[i]);
  rep(i, vecLength){
    while(!que.empty() && que.front() == 'x'){
      que.pop_front();
      front[i]++;
    }
    if(!que.empty()) que.pop_front();
    while(!que.empty() && que.back() == 'x'){
      que.pop_back();
      back[i]++;
    }
    if(!que.empty()) que.pop_back();
  }
  int count = 0;
  rep(i, vecLength){
    count += abs(front[i]-back[i]);
  }
  cout << count << endl;
  return 0;
}
    