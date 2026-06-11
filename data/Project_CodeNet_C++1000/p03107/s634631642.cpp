#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  string s;
  cin >> s;
  int cnt[2]={};
  for(int i=0; i<s.length(); i++){
    cnt[s[i]-'0']++;
  }
  int ans = 2*min(cnt[0], cnt[1]);
  cout << ans << endl;
  return 0;
}
