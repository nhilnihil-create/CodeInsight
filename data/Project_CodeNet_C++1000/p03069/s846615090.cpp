#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  deque<char> que;
  rep(i, n){
    que.push_back(str[i]);
  }
  while(!que.empty() && que.front() == '.'){
    que.pop_front();
  }
  while(!que.empty() && que.back() == '#'){
    que.pop_back();
  }
  vector<char> checkVec;
  while(!que.empty()){
    checkVec.push_back(que.front());
    que.pop_front();
  }
  int ans = 0;
  int smallest = 1000000007;
  for(int i=0; i<checkVec.size(); i++){
    if(checkVec[i] == '.') ans++;
  }
  smallest = ans;
  for(int i=0; i<checkVec.size(); i++){
    if(checkVec[i] == '.') ans--;
    else ans++;
    smallest = min(smallest, ans);
  }
  cout << smallest << endl;
  return 0;
}
  
  