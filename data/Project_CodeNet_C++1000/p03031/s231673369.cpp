#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<vector<int>> s;
vector<int> p;
int N, M;

bool judge(int bit){
  int cnt = 0;
  for(int i=0; i<M; i++){
    int state = 0;
    for(int j=0; j<s[i].size();j++){
      if (bit & (1<<s[i][j])) state += 1;
    }
    if (p[i] == (state %2)) cnt++;
  }
  return cnt==M;
}

int main() {
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int k;
    cin >> k;
    vector<int> s_tmp;
    for(int j=0;j<k;j++){
      int tmp;
      cin >> tmp;
      s_tmp.push_back(tmp-1);
    }
    s.push_back(s_tmp);
  }
  for(int i=0;i<M;i++){
    int tmp;
    cin >> tmp;
    p.push_back(tmp);
  }
  int ans =0;
  for(int bit=0; bit<(1<<N);++bit) if(judge(bit)) ans++;
  cout << ans;
  return 0;
}